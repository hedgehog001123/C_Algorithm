#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void)
{
	int a[N], i, j, gap, t;

	for (i = 0; i < N; i++) a[i] = rand();

	gap = 1;
    while (gap < N / 3) {
        gap = gap * 3 + 1;
    }

	while (gap > 0) {
		for (i = gap; i < N; i++) {
			for (j = i-gap; j >= 0; j=j-gap) {
				if (a[j]>a[j+gap]) {
					t = a[j];
					a[j] = a[j+gap];
					a[j+gap] = t;
				}
				else break;
			}
		}
		gap /= 3;
	}

	for (i = 0; i < N; i++) printf("%8d ", a[i]);
	printf("\n");

	return 0;
}
