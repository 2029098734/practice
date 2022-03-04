#include<stdio.h>
#include<stdint.h>

int main(void)
{
	float number = 0;
	while(scanf("%f",&number)){
		printf("%d\n",(uint32_t)(number + 0.5));
	}
	return 0;
}