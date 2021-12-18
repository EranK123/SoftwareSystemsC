CC=gcc
AR=ar
FLAGS= -g -Wall
LM = -lm
RCS = -rcs
SHARED = -shared
C = -c
O = -o

all: stringProg

stringProg: ex3.o
		$(CC) $(FLAGS) -o stringProg ex3.o

# libStringProg.a: ex3.o
# 		$(AR) $(RCS) libStringProg.a ex3.o

# libconnections.so: my_mat.o
#		$(CC) $(SHARED) -o libconnections.so my_mat.o

# main.o: main.c
# 		$(CC) $(FLAGS) -c main.c

ex3.o: ex3.c
		$(CC) $(FLAGS) -c ex3.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
