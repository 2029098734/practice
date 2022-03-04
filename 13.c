#include<stdio.h>
#include<string.h>

void exchange(char *a,char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	char buff[1000];
	int last = 0;
	int n = 0; 
	while(gets(buff)){
		n = strlen(buff);
		last = strlen(buff) - 1;
		for(int i = last - 1; i >= 0; i--)
		{
			if(*(buff + i) == ' ')
			{
				for(int j = 0; j <= (last - i -1) / 2; j++)
				{
					exchange(&buff[last - j], &buff[i + j + 1]);
				}
				last = i - 1;
			}
		}
		for(int j = 0; j <= last / 2; j++)
		{
			exchange(&buff[last - j], &buff[j]);
		}
		
		for(int i = n - 1; i >= 0; i--)
		{
			printf("%c",buff[i]);
		}
		printf("\n");
	}
	return 0;
}