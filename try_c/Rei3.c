#include <stdio.h>

#define Num 10

int main(void)
{
	int a[] = {10, 20, 79, 89, 34, 48, 52, 33, 20, 99};
	int jyuni[Num];
	int i, j;
	for (i = 0; i < Num; i++) {
		jyuni[i] = 1;
		for (j = 0; j < Num; j++) {
			if (a[j] > a[i]) jyuni[i]++;
		}
	}

	printf("  得点  順位\n");
	for (i = 0; i < Num; i++) {
		printf("%6d%6d\n", a[i], jyuni[i]);
	}

	return 0;
}
