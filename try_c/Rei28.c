#include <stdio.h>

#define N 4
int p[N+1];

void perm(int);

int main (void)
{
	int i;

	for (i = 1; i <= N; i++) p[i] = i;
	perm(1);

	return 0;
}

void perm(int i)
{
	int j, t;
	if (i < N) {
		for (j = i; j <= N; j++) {
			t = p[i];
			p[i] = p[j];
			p[j] = t;
			perm(i+1);
			t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
	}
	else {
		for (j = 1; j <= N; j++) printf("%d ", p[j]);
		printf("\n");
	}
	return;
}
