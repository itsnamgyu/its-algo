test : source.o submit.o lib.o
	gcc -o test source.o submit.o lib.o
	@./test
	@rm test
	@rm *.o

source.o : source.c
	gcc -c source.c

submit.o : ../submit.c
	gcc -c ../submit.c

lib.o : ../lib.c
	gcc -c ../lib.c
