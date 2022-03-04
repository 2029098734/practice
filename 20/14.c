#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct char_string{
	int index;
	char buff[100];
};

void compare(struct char_string *a, struct char_string *b)
{
	int len_a = strlen(a->buff);
	int len_b = strlen(b->buff);
	int len = len_a > len_b ? len_b : len_a;
	for(int i = 0; i < len; i++)
	{
		if(((a->buff[i] >= 'a' ? a->buff[i] - 'a' : a->buff[i] - 'A') > 
			(b->buff[i] >= 'a' ? b->buff[i] - 'a' : b->buff[i] - 'A')) 
			&&(a->index < b->index)){
				int exchange = a->index;
				a->index = b->index;
				b->index = exchange;
				return ;
			}
		}
	}
	if(len_b < len_a && a->index < b->index)
	{
		int exchange = a->index;
		a->index = b->index;
		b->index = exchange;
		return ;
	}
}

int main(void)
{
	struct char_string *list;
	int n = 0;
	while(scanf("%d", &n)){
		printf("n =%d\n",n);
		list = (struct char_string *)calloc(n, sizeof(struct char_string));
		for(int i = 0; i < n; i++){
			scanf("%s", (list + i)->buff);
			(list + i)->index = i;
		}
		printf("----------\n");
		for(int i = 0; i < n; i++){
			printf("%d ",(list + i)->index);
		}
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - i -1; j++){
				compare(list + j, list + j + 1);
			}
		}
		printf("\n----------\n");
		for(int i = 0; i < n; i++){
			printf("%d ",(list + i)->index);
		}
		printf("\n----------\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((list + j)->index == i){
					printf("%s\n",(list + j)->buff);
				}
			}
		}
	}
	free(list);
	return 0;
}