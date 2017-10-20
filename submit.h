void submit(int (*f) (void), char *questionString);

void submit_cases(
		char *title_string, 
		void **test_cases, int test_case_count,
		void *(*algo) (void *test_case), 
		int (*assess) (void *result));
