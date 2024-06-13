#include <stdio.h>

int gcd(int, int);

int main(void)
{
	int a, b;
	printf("せいすう２つ: ");
	scanf("%d %d", &a, &b);

	printf("gcd = %d\n", gcd(a, b));
	return 0;
}

int gcd(int m, int n)
{
	if (m == n) return m;
	if (m > n) return gcd(m-n, n);
	else return gcd(m, n-m);
}
