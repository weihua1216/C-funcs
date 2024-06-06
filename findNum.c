#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct num
{
	int n;
	struct num *next;
};

struct num *find(char word[]);

int main(void)
{
	char c[100];
	int out[100];
	gets(c);
	struct num *ans;
	ans = find(c);
	while ((*ans).next != NULL)
	{
		printf("%d\n", (*ans).n);
		ans = (*ans).next;
	}
	return 0;
}

struct num *find(char word[])
{
	struct num *head, *w, *temp;
	int i = 0, m = 0, record = 0;
	head = (struct num *)malloc(sizeof(struct num));
	(*head).next = NULL;
	w = head;
	for (record = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= '0' && word[i] <= '9')
			record++;
		else
		{
			if (record == 0)
				continue;
			else
			{
				for (int j = record - 1; j >= 0; j--)
					m += pow(10, j) * (word[i - j - 1] - '0');
				(*w).n = m;
				temp = (struct num *)malloc(sizeof(struct num));
				(*w).next = temp;
				(*temp).next = NULL;
				w = temp;
				record = 0;
				m = 0;
			}
		}
	}
	if (record != 0)
	{
		for (int j = record - 1; j >= 0; j--)
			m += pow(10, j) * (word[i - j - 1] - '0');
		(*w).n = m;
		temp = (struct num *)malloc(sizeof(struct num));
		(*w).next = temp;
		(*temp).next = NULL;
		w = temp;
		record = 0;
		m = 0;
	}
	return head;
}
