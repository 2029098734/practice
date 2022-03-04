#include<stdio.h>
#include<stdint.h>

int main(void)
{
	uint8_t char_list[128] = {0};
	uint8_t number = 0;
	char buff;
	while(buff = getchar()){
		if(buff == '\n')
			break;
		if(!char_list[buff])
		{
			char_list[buff] ++;
			number ++;
		}
	}
	printf("%d\n", number);
	return 0;
}