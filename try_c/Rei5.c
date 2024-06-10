#include <stdio.h>
#include <stdlib.h>

// モンテカルロ法

#define NUM 1000000

double rnd(void);

int main (void)
{
	double x, y, pai;
	int i, in = 0;

	for (i = 0; i < NUM; i++) {
		x = rnd();
		y = rnd();
		if (x * x + y * y <= 1) in++;
	}
	pai = (double)4*in/NUM;
	printf("πの値=%f\n", pai);
	printf("試行回数=%d\n", NUM);

	return 0;
}

double rnd(void)
{
	return (double)rand()/(RAND_MAX+0.1);
}
