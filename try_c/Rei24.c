#include <stdio.h>
#include <string.h>

char *search(char *, const char *);
void replace(char *, const char *, const char *);

int main(void)
{
	static char text[] = "This is a pen. That is a pencil.";

	replace(text, "pen", "cap");
	printf("%s\n", text);
}

void replace(char *text, const char *key, const char *rep)
{
	char *p;
	int i;
	p = search(text, key);
	while (p!=NULL) {
		for (i = 0; i < (int)strlen(rep); i++) p[i] = rep[i];
		p = search(p + strlen(key), key);
	}
}

char *search(char *text, const char *key)
{
	int m, n;
	char *p;

	m = strlen(text);
	n = strlen(key);
	for (p = text; p <= text+m-n; p++) {
		if (strncmp(p, key, n) == 0) return p;
	}
	return NULL;
}
