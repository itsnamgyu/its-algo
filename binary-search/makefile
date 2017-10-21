ALGO = algo_ho_recursive.c

test : source.o submit.o lib.o algo.o
	gcc -o test source.o submit.o lib.o algo.o

source.o : source.c
	gcc -c source.c

submit.o : ../submit.c
	gcc -c ../submit.c

lib.o : ../lib.c
	gcc -c ../lib.c

algo.o : $(ALGO)
	gcc -o algo.o -c $(ALGO)

clean :
	@rm test
	@rm *.o
