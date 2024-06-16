#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
	char name[20];
	char tel[20];
	struct tfield *pointer;
} *head;

struct tfield *talloc(void);
void genlist(void);
void displist(void);
void del(char *);

int main (void)
{
	char key[20];

	genlist();
	displist();

	while (printf("Key Name "), scanf("%s", key) != EOF) {
		del(key);
	}

	displist();
}

void del (char *key)
{
	struct tfield *p, *old;

	p = old = head;
	while (p != NULL) {
		if (strcmp(key, p->name) == 0) {
			if (p == head) head = p->pointer;
			else old->pointer = p->pointer;
			return;
		}
		old = p;
		p = p->pointer;
	}
	printf("キーデータが見つかりません\n");
}

void genlist(void)
{
	struct tfield *p;

	head = NULL;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->pointer = head;
		head = p;
	}
}

void displist(void)
{
	struct tfield *p;
	p = head;
	while (p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

struct tfield *talloc(void)
{
	return (struct tfield *)malloc(sizeof(struct tfield));
}
