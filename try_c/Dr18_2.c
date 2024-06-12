#include <stdio.h>

#define N 9

int main (void)
{
	int a[] = {80, 241, 35, 90, 140, 20, 14, 28, 99};
	int left = 0, right = N-1, shift, i, t;

	while (left < right) {
		for (i = left; i < right; i++) {
			if (a[i] > a[i+1]) {
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				shift = i;
			}
		}

		right = shift;
		for (i = right; i > left; i--) {
			if (a[i] < a[i-1]) {
				t = a[i];
				a[i] = a[i-1];
				a[i-1] = t;
				shift = i;
			}
		}
		left = shift;
	}

	for (i = 0; i < N; i++) printf("%d, ", a[i]);
	printf("\n");

	return 0;
}
