#include <stdio.h>

void swap(int *, int *);

int main(void) {
	int heap[100];
	int i, n, p, s, m;

	n = 1;
	while (scanf("%d", &heap[n]) != EOF) n++;
	m = n-1;
	for (i = m/2; i>= 1; i--) {
		p = i;
		s = 2 * p;
		while (s <= m) {
			if (s < m && heap[s+1] < heap[s]) break;
			if (heap[p] <= heap[s]) break;
			swap(&heap[p], &heap[s]);
			p = s;
			s = 2 * p;
		}
	}
	for (i = 1; i <= m; i++) printf("%d ", heap[i]);
	printf("\n");

	return 0;
}

void swap(int *a, int *b) {
	int w;
	w = *a;
	*a = *b;
	*b = w;
	return;
}
