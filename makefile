# $@ : the current target
# $^ : the current prerequisites
# $< : the first current prerequisite
# $? : prerequisites that have been modified
# $+ : same than $^ but removes doublons.


#=========================================
# FOLDERS / FILES MACROS
#=========================================
BIN = bin/
SRC = src/
INC = inc/
INCH= inc/includes.h
OBJ = obj/
TEST = test/


#=========================================
# 		COMPILATION INFORMATIONS
#=========================================
CC=gcc
CFLAGS=-Wall
LDFLAGS=-Wall -ly
LEAKFLAG = -fsanitize=address
BISONFLAGS =--report=all

#Name of executable
EXEC=tpcas

#Objects to compile:
OBJECTS= $(addprefix $(OBJ), \
		hash.o \
		symbolTab.o \
		utils.o \
		tree.o \
		tpcas_functions.o \
		programData.o \
		$(EXEC).tab.o \
		lex.yy.o \
		tree.o \
)

# INITIALISATION SECURITY 
$(shell mkdir -p bin obj)



#=========================================
# 		COMPILATION  RULES
#=========================================
all:
	@make -s generate_c_files
	@make -s generate_executable
#
#
#
#=========================================
# 		SCRIPT  RULES / OPERATIONS
#=========================================
#
#
#
generate_c_files:
	make bison_c
	make flex_c

bison_c:
	make $(EXEC).tab.c
	make $(EXEC).tab.h

flex_c:
	make lex.yy.c

# FLEX :
lex.yy.c: $(SRC)$(EXEC).lex $(EXEC).tab.h
	flex -o $(OBJ)$@ $< 
	$(info + $@  from $^)

# BISON : Src file
$(EXEC).tab.c: $(SRC)$(EXEC).y
	bison $< $(BISONFLAGS) -o $(OBJ)$@
	$(info + $@  from $^)

# BISON : Header file : required for flex
$(EXEC).tab.h: $(SRC)$(EXEC).y
	bison $< -d $(BISONFLAGS) -o $(OBJ)$@
	$(info + $@  from $^)

#
#
#
#=========================================
# 		OBJECTS RULES / OPERATIONS
#=========================================
#
#
#



#=========================================
# UNFORMAL COMPIL :
#=========================================

$(INCH): $(INC)struct.h $(INC)utils.h
	$(info + $@)

$(EXEC).tab.o: $(OBJ)$(EXEC).tab.c
	$(CC) -c $< $(CFLAGS) $(LEAKFLAG) -o $(OBJ)$@ 
	$(info +++ $@)

lex.yy.o: $(OBJ)lex.yy.c
	$(CC) -c $< $(CFLAGS) $(LEAKFLAG) -o $(OBJ)$@
	$(info +++ $@)

#=========================================
# COMPIL PROTOCOL :
#=========================================
$(OBJ)%.o: $(SRC)%.c $(INC)%.h $(INCH)
	$(CC) -c $< $(CFLAGS) $(LEAKFLAG) -o $@
	$(info +++ $@)

#Executable :
generate_executable:
	make $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) $(LEAKFLAG) -o $(BIN)$@
	$(info +++++ $@  from $^)
	
clean:
	$(info Cleaning Object Type)
	@rm $(OBJ)*
	$(info Done!)