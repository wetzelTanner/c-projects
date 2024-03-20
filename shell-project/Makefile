C = gcc
SRC = custom_shell.c
OBJ = custom_shell.o
CPARAMS = -g -Wall
EXE = shell

$(EXE): $(OBJ)
	$(C) $(OBJ) -o $(EXE)

$(OBJ): $(SRC)
	$(C) $(CPARAMS) -c $(SRC) -o $(OBJ)

clean:
	rm -f *.o $(EXE)