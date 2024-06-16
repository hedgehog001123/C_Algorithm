#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))
#define Min(a, b) ((a)<(b)?(a):(b))

double v[50];
char ope[50];
int pri[256];
int sp1, sp2;

void calc(void);

int main(void)
{
	const char *expression = "(1>2|2<8|3<4)|(9<2)", *p = expression;

	pri[')'] = 0;
	pri['|'] = 1;
	pri['<'] = pri['>'] = 2;
	pri['('] = 3;

	ope[0] = 0;
	pri[0] = -1;
	sp1 = sp2 = 0;
	while (*p != '\0') {
		if ('0' <= *p && *p <= '9') v[++sp2] = *p-'0';
		else {
			while (pri[*p] <= pri[ope[sp1]] && ope[sp1]!='(') calc();
			if (*p!=')') ope[++sp1] = *p;
			else sp1--;
		}
		p++;
	}

	while (sp1 > 0) calc();
	printf("%s = %f\n", expression, v[1]);
}

void calc(void) {
	switch (ope[sp1]) {
		case '|' : v[sp2-1]=(v[sp2-1]+v[sp2])/2;break;
		case '>' : v[sp2-1]=Max(v[sp2-1], v[sp2]);break;
		case '<' : v[sp2-1]=Min(v[sp2-1], v[sp2]);break;
	}
	sp2--;
	sp1--;
}
