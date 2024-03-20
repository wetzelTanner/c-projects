proj3: Main.o Rectangle.o Point.o
	gcc -lm Main.o Rectangle.o Point.o -o proj3

Main.o: Main.c
	gcc -g -lm -Wall -c Main.c -o Main.o

Rectangle.o: Rectangle.c
	gcc -g -lm -Wall -c Rectangle.c -o Rectangle.o

Point.o: Point.c
	gcc -g -lm -Wall -c Point.c -o Point.o
	
clean:
	rm -f *.o proj3