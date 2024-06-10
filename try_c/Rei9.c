#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x)))

int main(void) 
{
	int k;
	double a, b, n, h, x, s, sum;

	printf("積分区間 A,B ? ");
	scanf("%lf %lf", &a, &b);

	n = 1000;
	h = (b - a) / n;
	x = a;
	s = 0;
	for (k = 1; k <= n-1; k++) {
		x += h;
		s += f(x);
	}
	sum = h * ((f(a)+f(b))/2 + s);
	printf("	/%f\n", b);
	printf("	|    sqrt(4-x*x) = %f\n", sum);
	printf("	/%f\n", a);

	return 0;
	
}
