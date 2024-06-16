#include <stdio.h>

void hanoi (int, char, char);
#define Total 'a' + 'b' + 'c'

int main(void)
{
	int n;
	printf("円盤の枚数 ? ");
	scanf("%d", &n);

	hanoi(n, 'a', 'b');
}

void hanoi (int n, char a, char b)
{
	if (n > 0) {
		hanoi(n-1, a, Total-(a+b));
		printf("%d番の円盤を%cから%cに移動\n", n, a, b);
		hanoi(n-1, Total-(a+b), b);
	}
}
