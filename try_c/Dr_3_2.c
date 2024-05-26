#include <stdio.h>

#define Num 10
#define Max 36
#define Min -20
#define Bias 1-(Min)

int main(void) 
{
	int a[] = {-3, 2, 3, -1, -2, -6, 2, -1, 1, 5};
	int i, jyuni[Max+Bias+1];

	for (i = Min+Bias; i <= Max+Bias; i++) jyuni[i] = 0;
	for (i = 0; i < Num; i++) jyuni[a[i]+Bias]++;

	jyuni[0] = 1;
	for (i = Min+Bias; i <= Max+Bias; i++) {
		jyuni[i] = jyuni[i] + jyuni[i-1];
	}
	printf("  得点  順位\n");
	for (i = 0; i < Num; i++) printf("%6d%6d\n", a[i], jyuni[a[i]+Bias-1]);
	return 0;
}
