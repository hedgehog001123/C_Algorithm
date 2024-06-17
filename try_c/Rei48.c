#include <stdio.h>

void swap(int *, int *);

int main(void) {
	int heap[100];
	int i, n, p, s, m;

	n = 1;
	while (scanf("%d", &heap[n]) != EOF) {
		s = n;
		p = s/2;
		while (s >= 2 && heap[p] > heap[s]) {
			swap(&heap[p], &heap[s]);
			s = p;
			p = s/2;
		}
		n++;
	}
	m = n-1;
	while (m > 1) {
		swap(&heap[1], &heap[m]);
		m--;

		p = 1;
		s = 2 * p;
		while (s <= m) {
			if (s < m && heap[s+1] < heap[s]) s++;
			if (heap[p] <= heap[s]) break;
			swap(&heap[p], &heap[s]);
			p = s;
			s = 2 * p;
		}
	}
	for (i = 1; i < n; i++) printf("%d ", heap[i]);
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
