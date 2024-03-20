intproj: integral.o functions.o
	gcc integral.o functions.o -o intproj -lm

integral.o: integral.c
	gcc -g -Wall -c integral.c -o integral.o

functions.o: functions.c
	gcc -g -Wall -c functions.c -o functions.o
	
clean:
	rm -f *.o intproj