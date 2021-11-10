all: introsignals.o
	gcc -o main introsignals.o

introsignals.o: introsignals.c
	gcc -c introsignals.c

run:
	./main

clean:
	rm -rf introsignals.o
	rm -rf file.txt
	
