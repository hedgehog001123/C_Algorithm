#include <stdio.h>

int m[9][9]  = {{2,2,2,2,2,2,2,2,2},
				{2,0,0,0,0,0,0,0,2},
				{2,0,2,2,0,2,2,0,2},
				{2,0,2,0,0,2,0,0,2},
				{2,0,2,0,2,0,2,0,2},
				{2,0,0,0,0,0,2,0,2},
				{2,2,0,2,2,0,2,2,2},
				{2,0,0,0,0,0,0,0,2},
				{2,2,2,2,2,2,2,2,2}};

void visit(int, int);

int main(void)
{
	int i, j;

	visit(1, 1);

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) printf("%2d", m[i][j]);
		printf("\n");
	}
}

void visit(int i, int j)
{
	m[i][j]=1;
	if (m[i][j+1]==0) visit(i,j+1);
	if (m[i+1][j]==0) visit(i+1,j);
	if (m[i][j-1]==0) visit(i,j-1);
	if (m[i-1][j]==0) visit(i-1,j);
}
