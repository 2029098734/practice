#include<stdio.h>
#include<stdint.h>
#include<string.h>

int main(void)
{
	int number = 0;
	char compare;
	char buff[1000];
	gets(buff);
	compare = (char)getchar();
	if(compare >= 'a')
	{
		compare -= 32;
	}
	for(int i = 0; i < strlen(buff); i++)
	{
		if(*(buff + i) == compare || *(buff + i) == (compare + 32))
			number ++;
	}
	printf("%d",number);
	return 0;
}