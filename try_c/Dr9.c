#include <stdio.h>
#include <math.h>

// シンプソンの定積分

#define f(x) (sqrt(4-(x)*(x)))

int main(void) {
	int k;
	double a, b, n, h, fo, fe, sum;

	printf("積分区間 A, B ?");
	scanf("%lf %lf", &a, &b);

	n = 50;
	h = (b-a)/(2*n);
	fo = 0, fe = 0;
	for (k = 1; k <= 2 * n - 3; k += 2) {
		fo += f(a + h * k);
		fe += f(a + h * (k+1));
	}
	sum = (f(a) + f(b) + 4*(fo + f(b-h)) + 2 * fe) * h / 3;
	printf("	/%f\n", b);
	printf("	|  sqrt(4-x*x) =%f", sum);
	printf("	/%f\n", a);
}
