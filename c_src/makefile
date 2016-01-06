CC = cc
CFLAGS = -Wall -fPIC -shared
CFLAG = -Wall

objects = word.o RB_Tree.o myDict.o

dic_tree: $(objects)
	$(CC) $(CFLAGS) $(objects) -o ../dic_tree.so


word.o: word.h word.c 
	$(CC) $(CFLAGS) -c word.c

RB_Tree.o: RB_Tree.h RB_Tree.c word.h
	$(CC) $(CFLAGS) -c RB_Tree.c

myDict.o: myDict.c RB_Tree.h word.h
	$(CC) $(CFLAGS) -c myDict.c


.PHONY : clean
clean:
	-rm ../dic_tree.so $(objects)
