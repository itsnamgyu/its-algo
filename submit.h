void submit(int (*f) (void), char *questionString);

void submit_cases(
		char *title, 
		void **test_cases, char test_titles[][50], int test_case_count,
		void *(*algo) (void *test_case), 
		int (*assess) (void *result));
