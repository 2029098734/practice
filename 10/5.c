#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<math.h>

int main(void)
{
	char buff[10];
	uint32_t out = 0;
	while(scanf("%s",buff)){
		if(buff[0] != '0' || buff[1] != 'x')
		{
			break;
		}
		for(int i = 2; i < strlen(buff); i++)
		{
			if(buff[i] >= 97){
				buff[i] -= 32;
			}
			if(buff[i] >= 65){
				out += (buff[i] - 'A' + 10) * pow(16, (strlen(buff) - i - 1));
			}else{
				out += (buff[i] - '0') * pow(16, (strlen(buff) - i - 1));
			}
		}
		printf("%d\n",out);
		out = 0;
	}
	
	
	return 0;
}