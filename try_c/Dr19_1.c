#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void)
{
	int a[N], i, j, k, gap, t;

	for (i = 0; i < N; i++) a[i] = rand() % 10000;

	gap = N/2;

	while (gap > 0) {
		for (k = 0; k < gap; k++) {
			for (i = k + gap; i < N; i += gap) {
				for (j = i-gap; j >= k; j -= gap) {
					if (a[j] > a[j+gap]) {
						t = a[j];
						a[j] = a[j+gap];
						a[j+gap] = t;
					}
					else break;
				}
			}
		}
		gap = gap / 2;
	}

	for (i = 0; i < N; i++) printf("%8d ", a[i]);
	printf("\n");
}
