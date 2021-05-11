#include <stdio.h>

int main () {
	int a = 1;
	{
		int a = 2;
		printf("한글: %d\n", a);
	}
	printf("%d\n", a);
	return 0;
}