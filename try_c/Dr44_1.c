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
struct tnode *search(struct tnode *, char *);

int main(void) {
	char key[12];
	struct tnode *root, *p;

	root = NULL;
	while (scanf("%s", key) != EOF) {
		root = gentree(root, key);
	}

	rewind(stdin);
	while (printf("Search name -->"), scanf("%s", key) != EOF) {
		if ((p = search(root, key)) != NULL) printf("%sが見つかりました/n", p->name);
		else printf("見つかりません\n");
	}
	return 0;
}

struct tnode *search(struct tnode *p, char *key) {
	if (p == NULL || strcmp(key, p->name) == 0) return p;
	if (strcmp(key, p->name) < 0) return search(p->left, key);
	else serach(p->right, key);
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
