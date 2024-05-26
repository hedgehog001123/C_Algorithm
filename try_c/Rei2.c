// 度数分布

#include <stdio.h>

#define Num 10
#define kukan 6
#define dosu 10

int main(void)
{
	int a[] = {1 ,2 ,5 ,12 ,20 ,30 ,32, 38, 40, 50};
	int i, rank, histo[kukan];

	for (i = 0; i < kukan; i++) histo[i] = 0;

	for (i = 0; i < Num; i++) {
		rank = a[i] / dosu;
		if (0 <= rank && rank < kukan) histo[rank]++;
	}

	for (i = 0; i < kukan; i++) {
		if (i == kukan - 1) {
			printf("%3d      :%3d\n", i*dosu, histo[i]);
			break;
		}
		printf("%3d - %3d:%3d\n", i*dosu, (i+1)*dosu-1, histo[i]);
	};
	printf("-------------\n");
	printf("%3d - %3d:%3d\n", 0, dosu * (kukan - 1), Num);


	return 0;
}
