#include <stdio.h>

void quick(int[], int, int);

#define N 10

int main(void)
{
	static int a[] = {41,24,76,11,45,64,21,69,19,36};
	int k;

	quick(a, 0, N-1);

	for (k = 0; k < N; k++) printf("%4d", a[k]);
	printf("\n");
}

void quick(int a[], int left, int right)
{
	int s, t, i, j;

	if (left < right) {
		s = a[(left+right)/2];
		i = left - 1;
		j = right + 1;
		while (1) {
			while (a[++i]<s);
			while (a[--j]>s);
			if (i>=j) break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}

		quick(a, left, j-1);
		quick(a, j+1, right);
	}
}
