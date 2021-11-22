# $@ : the current target
# $^ : the current prerequisites
# $< : the first current prerequisite


#Tree
BIN = bin/
SRC = src/
OBJ = obj/
TEST = test/

#Flags and compilation
CC=gcc
CFLAGS=-Wall
LDFLAGS=-Wall -ly
BISONFLAGS =--report=all

#Name of executable
EXEC=tpcas

all:
	make generate_c_files
	make generate_o_files
	make generate_executable

#Script part :
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

# BISON : Src file
$(EXEC).tab.c: $(SRC)$(EXEC).y
	bison $< $(BISONFLAGS) -o $(OBJ)$@

# BISON : Header file : required for flex
$(EXEC).tab.h: $(SRC)$(EXEC).y
	bison $< -d $(BISONFLAGS) -o $(OBJ)$@


#Object part :
generate_o_files:
	make bison_o
	make flex_o
	make tree_o

bison_o:
	make $(EXEC).tab.o

flex_o:
	make lex.yy.o

tree_o:
	make tree.o


$(EXEC).tab.o: $(OBJ)$(EXEC).tab.c
	$(CC) -c $< $(CFLAGS) -o $(OBJ)$@

lex.yy.o: $(OBJ)lex.yy.c
	$(CC) -c $< $(CFLAGS) -o $(OBJ)$@

tree.o: $(SRC)tree.c $(SRC)tree.h
	$(CC) -c $< $(CFLAGS) -o $(OBJ)$@

#Executable :
generate_executable:
	make $(EXEC)

$(EXEC): $(OBJ)$(EXEC).tab.o $(OBJ)lex.yy.o $(OBJ)tree.o
	$(CC) $^ $(LDFLAGS) -o $(BIN)$@
	
clean:
	$(info Cleaning Object Type)
	@rm $(OBJ)*
	$(info Done!)