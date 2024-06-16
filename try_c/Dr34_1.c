#include <stdio.h>
#include <stdlib.h>

struct tfield {
	char name[20];
	char tel[20];
	struct tfield *pointer;
};

struct tfield *talloc(void);

int main (void)
{
	struct tfield *head, *p, *old;

	head = talloc();
	scanf("%s %s", head->name, head->tel);
	old = head;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		old->pointer = p;
		old = p;
	}

	p = head;
	while (p!=NULL) {
		printf("%15s%15s/n", p->name, p->tel);
		p = p->pointer;
	}
}

struct tfield *talloc(void)
{
	return (struct tfield *)malloc(sizeof(struct tfield));
}
