#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main(void)
{
	uint16_t number = 0;
	uint32_t *list = NULL;
	while(scanf("%d", &number)){
		list = (uint32_t *)calloc(number * 2, sizeof(uint32_t));
		for(int i = 0; i < number; i++){
			scanf("%d",list + i * 2);
			scanf("%d",list + i * 2 + 1);
		}
		for(int i = 0; i < number; i++){
			for(int j = 0; j < number - i - 1; j++){
				if(*(list + j * 2) > *(list + (j + 1) * 2))
				{
					*(list + j * 2) = *(list + j * 2) ^ *(list + (j + 1) * 2);
					*(list + (j + 1) * 2) = *(list + j * 2) ^ *(list + (j + 1) * 2);
					*(list + j * 2) = *(list + j * 2) ^ *(list + (j + 1) * 2);
					*(list + j * 2 +1) = *(list + j * 2 +1 ) ^ *(list + (j + 1) * 2 + 1);
					*(list + (j + 1) * 2 + 1) = *(list + j * 2 + 1) ^ *(list + (j + 1) * 2 + 1);
					*(list + j * 2 + 1) = *(list + j * 2 + 1) ^ *(list + (j + 1) * 2 + 1);
				}
			}
		}
		int last = 0;
		for(int i = 0; i < number - 1; i++){
			if(*(list + i * 2) == *(list + (i + 1) * 2))
			{
				*(list + (i + 1) * 2 + 1) += *(list + i * 2 + 1);
			}else{
				printf("%d %d\n", *(list + i * 2), *(list + i * 2 + 1));
				last = i;
			}
		}
		if(*(list + (number - 1) * 2) != *(list + last * 2))
		{
			printf("%d %d\n", *(list + (number - 1) * 2), *(list + (number - 1) * 2 + 1));
		}
	}
	return 0;
}