#include <stdio.h>
#include <string.h>

#define N 6

int main (void) {
	struct girl {
		char name[20];
		int age;
	} *t, *p[N], a[] = {{"Ann", 5}, {"Rolla", 3}, {"Nancy", 2}, {"Eluza", 1}, {"Candy", 4}, {"Mari", 6}};
	char *min;
	int s, i, j;

	for (i = 0; i < N; i++) p[i] = &a[i];

	for (i = 0; i < N; i++) printf("%10s%4d\n", p[i]->name, p[i]->age);
	printf("-----\n");

	for (i = 0; i < N-1; i++) {
		min = p[i]->name;
		s = i;
		for (j = i + 1; j < N; j++) {
			if (strcmp(p[j]->name, min) < 0) {
				min = p[j]->name;
				s = j;
			}
		}
		t = p[i];
		p[i] = p[s];
		p[s] = t;
	}

	for (i = 0; i < N; i++) printf("%10s%4d\n", p[i]->name, p[i]->age);
}
