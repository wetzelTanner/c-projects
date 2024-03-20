llnode: LLNode_main.o LLNode.o
	gcc LLNode_main.o LLNode.o -o llnode

LLNode_main.o: LLNode_main.c
	gcc -g -Wall -c LLNode_main.c -o LLNode_main.o

LLNode.o: LLNode.c
	gcc -g -Wall -c LLNode.c -o LLNode.o
	
clean:
	rm -f *.o llnode