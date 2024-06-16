#include <stdio.h>

int m[7][7]  = {{2,2,2,2,2,2,2},
				{2,0,0,0,0,0,2},
				{2,0,2,0,2,0,2},
				{2,0,0,2,0,2,2},
				{2,2,0,2,0,2,2},
				{2,0,0,0,0,0,2},
				{2,2,2,2,2,2,2}};

int Si, Sj, Ei, Ej, success;

int visit(int, int);

int main(void)
{
	success = 0;
	Si=1, Sj=1;
	Ei=5, Ej=5;

	printf("\n迷路の探索\n");
	if (visit(Si, Sj) == 0) printf("出口は見つかりませんでした\n");
	printf("\n");
}

int visit(int i, int j)
{
	m[i][j] = 1; // 訪れたら1

	if (i==Ei && j==Ej) success = 1;

	if (success!=1 && m[i][j+1]==0) visit(i,j+1);
	if (success!=1 && m[i+1][j]==0) visit(i+1,j);
	if (success!=1 && m[i][j-1]==0) visit(i,j-1);
	if (success!=1 && m[i-1][j]==0) visit(i-1,j);

	if (success==1) printf("(%d,%d)", i, j);
	return success;
}
