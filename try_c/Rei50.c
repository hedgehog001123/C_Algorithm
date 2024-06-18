#include <stdio.h>

#define Max 100
#define nil -1

int getch(void) {
	rewind(stdin);
	return getchar();
}

int main(void) {
	struct tnode {
		int left;
		char node[100];
		int right;
	};
	static struct tnode a[Max]   = {{1  ,"外国人ですか？",2},
									{3  ,"科学者ですか？",4},
									{nil,"吉田茂"       ,nil},
									{nil,"エジソン"     ,nil},
									{5  ,"哲学者ですか？",6},
									{nil,"ソクラテス"   ,nil},
									{nil,"バッハ"       ,nil}};
	int p, lp = 6, c;

	do {
		p = 0;
		while (a[p].left != nil) {
			printf("\n%s y/n ", a[p].node);
			c = getch();
			if (c == 'y' || c == 'Y') p = a[p].left;
			else p = a[p].right;
		}

		printf("\n答えは %s です。\n正しいですか y/n ", a[p].node);
		c = getch();

		if (c == 'n' || c == 'N') {
			a[lp+1] = a[p];

			printf("\n あなたの考えは ? ");
			scanf("%s", a[lp+2].node);
			a[lp+2].left = a[lp+2].right = nil;
			printf("%s と %sを区別する質問は ?", a[lp+1].node, a[lp+2].node);
			scanf("%s", a[p].node);
			printf("yesの項目は%sで良いですか y/n", a[lp+1].node);
			c=getch();
			if (c == 'y' || c == 'Y') {
				a[p].left = lp + 1;
				a[p].right = lp + 2;
			}
			else {
				a[p].left = lp + 2;
				a[p].right = lp + 1;
			}
			lp = lp + 2;
		}
	} while (printf("\n 続けますか y/n"), (c=getch()) =='y' || c=='Y');
	printf("\n");

	return 0;
}
