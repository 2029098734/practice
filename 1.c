#include<stdio.h>
#include<string.h>
#include<stdint.h>
int main(void)
{
	char buff[5000];
	gets(buff);
	printf("%s\n",buff);
	uint32_t buff_len = strlen(buff);
	printf("%d\n",buff_len);
	uint32_t last_space = 0;
	for(int i = buff_len - 1; i >= 0; i--)
	{
		if(*(buff + i) == ' ')
		{
			last_space = i + 1; 
			break;
		}
	}
	printf("%d",buff_len - last_space);
	return 0;
}