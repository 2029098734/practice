#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct out{
	uint16_t i;
	uint16_t *address;
	struct out *next;
};
int main(void)
{
	uint16_t i = 0;
	uint16_t *number;
	struct out *first_out;
	struct out *cur_out;
	struct out out_number;
	cur_out = &out_number;
	first_out = &out_number;
	for(;;){
		if(scanf("%d",&i) == 0){
			cur_out->next = NULL;
			break;
		}
		printf("i = %d\n", i);
		if(cur_out != first_out)
		{
			cur_out->next = (struct out*)malloc(sizeof(struct out));
			cur_out = cur_out->next;
		}
		number = (uint16_t *)malloc(sizeof(uint16_t) * i);
		for(int n = 0; n < i; n++)
		{
			scanf("%d",number + n);
		}
		printf("cccc");
		cur_out->i = i;
		cur_out->address = number;
		fflush(stdin); 										//回收标准输入流中的回车
	}
	
	cur_out = first_out;
	for(;;){
		for(int m = 0; m < cur_out->i; m++){
			for(int n = 0; n < cur_out->i - m - 1; n++){
				if(*(cur_out->address + n) > *(cur_out->address + n + 1)){
					*(cur_out->address + n) = *(cur_out->address + n + 1) ^ *(cur_out->address + n);
					*(cur_out->address + n + 1) = *(cur_out->address + n + 1) ^ *(cur_out->address + n);
					*(cur_out->address + n) = *(cur_out->address + n + 1) ^ *(cur_out->address + n);
				}
			}
		}
		if((cur_out = cur_out->next) == NULL)
			break;
	}
	cur_out = first_out;
	for(;;)
	{
		printf("%d\n", *(cur_out->address));
		for(int m = 1; m < cur_out->i; m++){
			if(*(cur_out->address + m) != *(cur_out->address + m - 1))
			{
				printf("%d\n", *(cur_out->address + m));
			}
		}
		if((cur_out = cur_out->next) == NULL)
			break;
	}
	return 0;
}