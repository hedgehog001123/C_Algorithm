#include <stdio.h>
#include <string.h>

#define N 6

int main (void) {
	struct girl {
		char name[20];
		int age;
	} a[] = {{"Ann", 5}, {"Rolla", 3}, {"Nancy", 2}, {"Eluza", 1}, {"Candy", 4}, {"Mari", 6}};
	char key[20];
	int i, flag=0;

	printf("検索するdata ? ");
	scanf("%s", key);

	for (i = 0; i < N; i++) {
		if (strcmp(key, a[i].name) == 0) {
			printf("%s %d\n", a[i].name, a[i].age);
			flag = 1;
			break;
		}
	}
	
	if (flag != 1) printf("見つかりませんでした\n");

	return 0;
}
