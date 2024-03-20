C = gcc
SRC = user_calc.c
OBJ = user_calc.o
CPARAMS = -g -Wall
EXE = usercalc

$(EXE): $(OBJ)
	$(C) $(OBJ) -o $(EXE)

$(OBJ): $(SRC)
	$(C) $(CPARAMS) -c $(SRC) -o $(OBJ)

clean:
	rm -f *.o $(EXE)