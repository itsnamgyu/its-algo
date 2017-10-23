test : source.o submit.o lib.o algo.o
	gcc -O2 -o test source.o submit.o lib.o algo.o

source.o : source.c
	gcc -O2 -c source.c

submit.o : ../submit.c
	gcc -O2 -c ../submit.c

lib.o : ../lib.c
	gcc -O2 -c ../lib.c

algo.o : algo.c
	gcc -O2 -c algo.c

clean :
	@rm test
	@rm *.o
