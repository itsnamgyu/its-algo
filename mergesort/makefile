test : source.o submit.o lib.o
	gcc -O2 -o test source.o submit.o lib.o

source.o : source.c
	gcc -O2 -c source.c

submit.o : ../submit.c
	gcc -O2 -c ../submit.c

lib.o : ../lib.c
	gcc -O2 -c ../lib.c

clean :
	@rm test
	@rm *.o
