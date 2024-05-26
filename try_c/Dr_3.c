#include <stdio.h>

#define Num 10
#define Max 100
#define Min 10

int main(void) 
{
	int a[] = {10, 20, 79, 89, 34, 48, 52, 33, 20, 99};
	int i, jyuni[Max+2];

	for (i = Min; i <= Max; i++) jyuni[i] = 0;
	for (i = 0; i < Num; i++) jyuni[a[i]]++;

	jyuni[Max + 1] = 1;
	for (i = Max; i >= Min; i--) {
		jyuni[i] = jyuni[i] + jyuni[i+1];
	}
	printf("  得点  順位\n");
	for (i = 0; i < Num; i++) printf("%6d%6d\n", a[i], jyuni[a[i]+1]);
	return 0;
}
