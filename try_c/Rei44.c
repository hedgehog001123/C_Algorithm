#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	struct tnode *left;
	char name[12];
	struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);

int main(void) {
	char dat[12];
	struct tnode *root, *p = NULL;

	root = NULL;
	while (scanf("%s", dat) != EOF) {
		root = gentree(root, dat);
	}
	p = root;
	while (p != NULL) {
		printf("%s\n", p->name);
		p = p->left;
	}
	return 0;
}

struct tnode *gentree(struct tnode *p, char *w) {
	if (p == NULL) {
		p = talloc();
		strcpy(p->name, w);
		p->left = p->right = NULL;
	}
	else if (strcmp(w, p->name) < 0) p->left = gentree(p->left, w);
	else p->right = gentree(p->right, w);

	return p;
}

struct tnode *talloc(void) {
	return (struct tnode *)malloc(sizeof(struct tnode));
}
