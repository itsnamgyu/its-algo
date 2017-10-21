void submit(int (*f) (void), char *questionString);

void submit_cases(
		char *title, 
		void **test_cases, char test_titles[][50], int test_case_count,
		void *(*algo) (void *test_case), 
		int (*assess) (void *result));

void submit_cases_repeatedly(
		char *title, 
		void *load_test_case(int index), 
		void load_test_title(int index, char test_title[50]), 
		int test_case_count,
		void *(*algo) (void *test_case), 
		int (*assess) (void *result, int index),
		void (*free_all) (void *test_case, void *result));
