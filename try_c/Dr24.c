#include <stdio.h>
#include <string.h>

void replace(char *, const char *, const char *);
char *search(char *, const char *);

int main(void)
{
	int k;
	static char text[][128] = {"This is a pen. That is a pencil.",
	"I have a pon.",
	"ponnnnnu",
	"Zannko",
	""};

	k = 0;
	while (text[k][0] != '\0') {
		replace(text[k], "pen", "BO");
		replace(text[k], "a", "EE");
		printf("%s\n", text[k]);
		k++;
	}
}

void replace(char *text, const char *key, const char *rep)
{
	char *p, buf[128];

	p = search(text, key);
	while (p!=NULL) {
		*p = '\0';
		strcpy(buf, p+strlen(key));
		strcat(text, rep);
		strcat(text, buf);
		p = search(p+strlen(rep), key);
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
