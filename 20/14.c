#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct char_string{
	char* buff;
};

void compare(char **a,char **b)
{
	int len_a = strlen(*a);
	int len_b = strlen(*b);
	int len = len_a > len_b ? len_b : len_a;
	
	for(int i = 0; i < len; i++)
	{
		if(((*(*a + i) >= 'a' ? *(*a + i) - 'a' : *(*a + i) - 'A') < 
			(*(*b + i) >= 'a' ? *(*b + i) - 'a' : *(*b + i) - 'A')) ){
				return ;
		}else if(((*(*a + i) >= 'a' ? *(*a + i) - 'a' : *(*a + i) - 'A') > 
			(*(*b + i) >= 'a' ? *(*b + i) - 'a' : *(*b + i) - 'A')) ){
				
			char* exchange = *a;
			*a = *b;
			*b = exchange;
			
			return ;
		}
		
	}
	if(len_b < len_a)
	{
		char* exchange = *a;
		*a = *b;
		*b = exchange;
		
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
			(list + i)->buff = (char *)calloc(100, sizeof(char));
			scanf("%s", (list + i)->buff);
		}
		printf("----------\n");
		
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - i -1; j++){
				printf("\n||%s  %s||\n",(list + j)->buff, (list + j + 1)->buff);
				compare(&(list + j)->buff, &(list + j + 1)->buff);
				printf("\n--%s  %s--\n",(list + j)->buff, (list + j + 1)->buff);
			}
		}
		
		printf("\n----------\n");
		for(int i = 0; i < n; i++){
			printf("%s\n",(list + i)->buff);
			free((list + i)->buff);
		}
		free(list);
	}
	return 0;
}