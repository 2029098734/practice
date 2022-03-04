#include<stdio.h>
#include<stdint.h>

int main(void)
{
	uint32_t input;
	uint32_t half;
	while(scanf("%d",&input))
	{ 	half = input / 2;
		for(uint32_t i = 2;i <= half;)
		{
			if(input % i == 0)
			{
				printf("%d ",i);
				input = input / i;
				half = input / 2;
				i = 2;
				continue;
			}
			i++;
		}
		if(input != 1)
		{
			printf("%d\n",input);
		}
	}
	return 0;
}