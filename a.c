#include <stdio.h>

int main(void) {
	char s[3] = { 0 };

	scanf("%c %c %c", s, s + 1, s + 2);
	printf("%c %c %c\n", s[0], s[1], s[2]);


	return 0;
}
