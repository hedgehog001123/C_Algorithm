#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	struct tnode *left;
	char ope;
	struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);
void prefix(struct tnode *);
void infix(struct tnode *);
void postfix(struct tnode *);

int main(void) {
	struct tnode *root;
	char expression[] = "ab*cd+e/-";

	root = NULL;
	root = gentree(root, expression);

	printf("\nprefix  = ");prefix(root);
	printf("\ninfix   = ");infix(root);
	printf("\npostfix = ");postfix(root);
	printf("\n");
}

struct tnode *gentree(struct tnode *p, char *w) {
	int n;

	n = strlen(w);
	p = talloc();
	p->ope = w[n-1];
	w[n-1] = '\0';
	if (p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/') {
		p->right = gentree(p->right, w);
		p->left = gentree(p->left, w);
	}
	else {
		p->left = p->right = NULL;
	}
	return p;
}

void prefix(struct tnode *p) {
	if (p != NULL) {
		putchar(p->ope);
		prefix(p->left);
		prefix(p->right);
	} 
}

void infix(struct tnode *p) {
	if (p != NULL) {
		infix(p->left);
		putchar(p->ope);
		infix(p->right);
	} 
}

void postfix(struct tnode *p) {
	if (p != NULL) {
		postfix(p->left);
		postfix(p->right);
		putchar(p->ope);
	} 
}

struct tnode *talloc(void) {
	return (struct tnode *)malloc(sizeof(struct tnode));
}
