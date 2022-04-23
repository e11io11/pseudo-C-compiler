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
LEAKFLAG = -Wall #-fsanitize=address
CC_OPTIONS = -nostartfiles -no-pie
BISONFLAGS =--report=all 
ASM_CC = nasm -f elf64

#Name of executable
EXEC=$(BIN)tpcc

#Pattern-Name of the exec-related generated files
TPCAS=tpcas

#Objects to compile:
OBJECTS= $(addprefix $(OBJ), \
		hash.o \
		symbolTab.o \
		utils.o \
		tree.o \
		tpcas_functions.o \
		programData.o \
		$(TPCAS).tab.o \
		lex.yy.o \
		tree.o \
		debug.o \
		debug_messages.o \
		type.o \
		translator.o \
)

# INITIALISATION SECURITY 
$(shell mkdir -p bin obj)



#=========================================
# 		COMPILATION  RULES
#=========================================
all:
	@make -s generate_c_files
	@make -s generate_executable

asm:
	@./$(EXEC) --t < test/good/testAsm.tpc
	@make -s output
	./output

t:
	@./$(EXEC) --t < test/good/testvar.tpc
	@make -s output
	./output
#
#
#
#=========================================
# 		SCRIPT  RULES / OPERATIONS
#=========================================
#
#
#

output: $(OBJ)output.o $(OBJ)utils.o
	$(CC) -o $@ $^ $(CC_OPTIONS)

generate_c_files:
	make bison_c
	make flex_c

bison_c:
	make $(TPCAS).tab.c
	make $(TPCAS).tab.h

flex_c:
	make lex.yy.c

# FLEX :
lex.yy.c: $(SRC)$(TPCAS).lex $(TPCAS).tab.h
	flex -o $(OBJ)$@ $< 
	$(info + $@  from $^)

# BISON : Src file
$(TPCAS).tab.c: $(SRC)$(TPCAS).y
	bison $< $(BISONFLAGS) -o $(OBJ)$@
	$(info + $@  from $^)

# BISON : Header file : required for flex
$(TPCAS).tab.h: $(SRC)$(TPCAS).y
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

$(TPCAS).tab.o: $(OBJ)$(TPCAS).tab.c
	$(CC) -c $< $(CFLAGS) $(LEAKFLAG) -o $(OBJ)$@ 
	$(info +++ $@)

lex.yy.o: $(OBJ)lex.yy.c
	$(CC) -c $< $(CFLAGS) $(LEAKFLAG) -o $(OBJ)$@
	$(info +++ $@)

$(BIN)%.o: %.asm
	$(ASM_CC) -o $@ $^
	$(info ++ $@ from $^)

#=========================================
# COMPIL PROTOCOL :
#=========================================
$(OBJ)%.o: $(SRC)%.c $(INC)%.h $(INCH)
	$(CC) -c $< $(CFLAGS) $(LEAKFLAG) -o $@
	$(info +++ $@)

#Executable :
generate_executable:
	make $(TPCAS)

$(TPCAS): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) $(LEAKFLAG) -o $(EXEC)
	$(info +++++ $@  from $^)
	
clean:
	$(info Cleaning Object Type)
	@rm $(OBJ)*
	$(info Done!)