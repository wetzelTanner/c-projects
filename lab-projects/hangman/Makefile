C = gcc
SRC = lab2_hangman.c
OBJ = lab2_hangman.o
CPARAMS = -g -Wall
EXE = hangman_lab

$(EXE): $(OBJ)
	$(C) $(OBJ) -o $(EXE)

$(OBJ): $(SRC)
	$(C) $(CPARAMS) -c $(SRC) -o $(OBJ)

clean:
	rm -f *.o $(EXE)