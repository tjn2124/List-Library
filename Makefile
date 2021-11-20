CC = gcc


CFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g

LDLIBS = libmylist.a

libmylist.a:  mylist.o
	ar rcs libmylist.a mylist.o

mylist-test: mylist-test.o mylist.o libmylist.a

mylist-test.o: mylist-test.c mylist.c mylist.h

mylist.o: mylist.c mylist.h 


.PHONY: clean
clean:
	rm -f *.o *.a mylist-test

.PHONY: valgrind
	valgrind --leak-check=yes

.PHONY: all
all: clean main


