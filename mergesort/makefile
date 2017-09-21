test : source.o submit.o
	gcc -o test source.o submit.o
	@echo "Submitting source..."
	@./test
	@echo "Submit complete."
	@rm test
	@rm *.o

source.o : source.c ../submit.h
	gcc -c source.c

submit.o : ../submit.c ../submit.h
	gcc -c ../submit.c
