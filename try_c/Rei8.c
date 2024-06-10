#include <stdio.h>

unsigned rndnum = 13;

unsigned irnd(void);

int main(void)
{
	int j;
	for (j = 0; j < 100; j++) {
		printf("%8d", irnd());
		if (j % 10 == 9) printf("\n");
	}
	printf("\n");

	return 0;
}

unsigned irnd(void)
{
	rndnum = (rndnum*109 + 1021) % 32768;
	return rndnum;
}
