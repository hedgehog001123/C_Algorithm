#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
	struct tfield *left;
	char name[20];
	char tel[20];
	struct tfielf *right;
};

struct tfield *talloc(void);

int main(void) 
{
	struct tfield *head, *tail, *p;

	tail = NULL;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->left = tail;
		tail = p;
	}

	p = tail;
	head = NULL;
	while (p!=NULL) {
		p->right = head;
		head = p;
		p = p->left;
	}

	printf("\n順方向リスト\n");
	p = head;
	while (p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->right;
	}

	printf("\n逆方向リスト\n");
	p = tail;
	while (p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;
	}
}

struct tfield *talloc(void)
{
	return (struct tfield *)malloc(sizeof(struct tfield));
}
