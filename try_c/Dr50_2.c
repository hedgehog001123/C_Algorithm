#include <stdio.h>
#include <stdlib.h>

#define Rec 34L
#define Leaf -1
FILE *fp;

struct tnode {
	struct tnode *left;
	char node[100];
	struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *readtree(struct tnode *);
void writetree(struct tnode *);
int getch(void) {
	rewind(stdin);
	return getchar();
}

int main(void) {
	struct tnode *root=NULL, *p, *q1, *q2;
	int c;

	if ((fp = fopen("dbase.dat", "r")) == NULL) {
		root = talloc();
		printf("初期ノード ? ");
		scanf("%s", root->node);
		root->left = root->right = NULL;
	}
	else {
		root = readtree(root);
		fclose(fp);
	}
	do {
		p = root;
		while (p->left != NULL) {
			printf("\n%s y/n ", p->node);
			c = getch();
			if (c=='Y' || c=='y') p = p->left;
			else p = p->right;
		}

		printf("\n答えは %s です。\n正しいですか y/n", p->node);
		c = getch();

		if (c=='n' || c=='N') {
			q1 = talloc();
			*q1 = *p;

			q2 = talloc();
			printf("\nあなたの考えは ? ");
			scanf("%s", q2->node);
			q2->left = q2->right = NULL;

			printf("%sと%sを区別する質問は ? ", q1->node, q2->node);
			scanf("%s", p->node);
			printf("yesの項目は%sで良いですか y/n", q1->node);
			c = getch();
			if (c=='Y'||c=='y') {
				p->left = q1;
				p->right = q2;
			}
			else {
				p->left = q2;
				p->right = q1;
			}
		}
	} while (printf("\n続けますか y/n "), c=getch(), c=='Y'||c=='y');
	printf("\n");
	if ((fp = fopen("dbase.dat", "w")) != NULL) {
		writetree(root);
		fclose(fp);
	}
}

struct tnode *readtree(struct tnode *p) {
	int flag;

	p = talloc();
	fscanf(fp, "30s%4d", p->node, &flag);
	if (flag == Leaf) p->left = p->right = NULL;
	else {
		p->left = readtree(p->left);
		p->right = readtree(p->right);
	}
	return p;
}

void writetree(struct tnode *p) {
	if (p != NULL) {
		if (p->left == NULL) fprintf(fp, "30s%4d", p->node, Leaf);
		else fprintf(fp, "%30s%4d", p->node, !Leaf);
		writetree(p->left);
		writetree(p->right);
	}
}

struct tnode *talloc(void) {
	return (struct tnode *)malloc(sizeof(struct tnode));
}
