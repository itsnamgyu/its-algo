ALGO = algo_recursive_ho.c

test : source.o submit.o lib.o algo.o
	gcc -O2 -g -o test source.o submit.o lib.o algo.o

source.o : source.c
	gcc -O2 -g -c source.c

submit.o : ../submit.c
	gcc -O2 -g -c ../submit.c

lib.o : ../lib.c
	gcc -O2 -g -c ../lib.c

algo.o : $(ALGO)
	gcc -O2 -g -o algo.o -c $(ALGO)

clean :
	@rm test
	@rm *.o
