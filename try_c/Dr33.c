#include <stdio.h>

#define MaxSize 100
int queue[MaxSize];
int head = 0, tail = 0;
int queuein(int);
int queueout(int *);
void disp(void);

int main(void)
{
	int c, n;

	while (printf("]"), (c = getchar()) != EOF) {
		rewind(stdin);
		if (c == 'i' || c == 'I') {
			printf("data--> ");
			scanf("%d", &n);
			rewind(stdin);
			if (queuein(n) == -1) printf("待ち行列が一杯です\n");
		}
		if (c == 'o' || c == 'O') {
			if (queueout(&n) == -1) printf("待ち行列は空です\n");
			else printf("queue data --> %d\n", n);
		}
		if (c == 'l' || c == 'L') {
			disp();
			break;
		}
	}
}

int queuein(int n)
{
	if ((tail+1)%MaxSize != head) {
		queue[tail] = n;
		tail++;
		tail=tail%MaxSize;
		return 0;
	}
	else return -1;
}

int queueout(int *n)
{
	if (tail != head) {
		*n = queue[head];
		head++;
		head = head % MaxSize;
		return 0;
	}
	else return -1;
}

void disp(void)
{
	int i;

	i = head;
	while (i!=tail) {
		printf("%d\n", queue[i]);
		i++;
		i = i%MaxSize;
	}
}
