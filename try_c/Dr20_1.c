#include <stdio.h>
#include <string.h>

#define N 6

int main (void) {
	struct girl {
		char name[20];
		int age;
	} a[N+1] = {{"Ann", 5}, {"Rolla", 3}, {"Nancy", 2}, {"Eluza", 1}, {"Candy", 4}, {"Mari", 6}};
	char key[20];
	int i;

	printf("検索するdata ? ");
	scanf("%s", key);

	strcpy(a[N].name, key);
	i = 0;

	while (strcmp(key, a[i].name) != 0) i++;

	if (i < N) printf("%s %d\n", a[i].name, a[i].age);
	else printf("見つかりませんでした\n");

	return 0;
}
