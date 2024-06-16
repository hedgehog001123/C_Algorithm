#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
	char name[20];
	char tel[20];
	struct tfield *pointer;
};

struct tfield *talloc(void);

int main (void)
{
	struct tfield *head, *p, sentinel;
	char key[20];

	head = &sentinel;

	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		p->pointer = head;
		head = p;
	}

	rewind(stdin);
	while (printf("Key name "), scanf("%s", key) != EOF){
		strcpy(sentinel.name, key);
		p = head;
		while (strcmp(p->name, key) != 0) p = p->pointer;
		if (p != &sentinel) printf("%s %s\n", p->name, p->tel);
		else printf("見つかりません\n");
	}

}

struct tfield *talloc(void)
{
	return (struct tfield *)malloc(sizeof(struct tfield));
}
