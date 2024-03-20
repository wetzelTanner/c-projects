C = gcc
SRC = lab1_circuit.c
OBJ = lab1_circuit.o
CPARAMS = -g -Wall
EXE = circuit_lab

$(EXE): $(OBJ)
	$(C) $(OBJ) -o $(EXE)

$(OBJ): $(SRC)
	$(C) $(CPARAMS) -c $(SRC) -o $(OBJ)

clean:
	rm -f *.o $(EXE)