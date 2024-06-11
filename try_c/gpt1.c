// Stirlingの近似式

#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define E 2.71828182

// 階乗を計算する関数
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Stirlingの近似式に基づく階乗の近似値を計算する関数
double stirling_approximation(int n) {
    return sqrt(2 * PI * n) * pow(n / E, n);
}

int main() {
    int n;

	for (n = 0; n <= 20; n++) {	
		// n! の実際の値とStirlingの近似値を計算
		unsigned long long fact = factorial(n);
		double stirling = stirling_approximation(n);

		printf("n!       : %llu\n", fact);
		printf("Stirling : %.15f\n", stirling);
		printf("Difference: %.15f\n", fabs(fact - stirling));
	}

    return 0;
}
