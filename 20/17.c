#include<stdio.h>
#include<string.h>
#include<stdint.h>

void move(char dir, char dis, int32_t *x, int32_t *y)
{
	switch(dir){
		case 'W':
			*y = *y + dis;
			break;
		case 'A':
			*x = *x - dis;
			break;
		case 'S':
			*y = *y - dis;
			break;
		case 'D':
			*x = *x + dis;
			break;
		default:
			break;
	}
}

int main(void)
{
	char input[10000];
	int cur;
	int last = 0;
	char dir;
	char dis;
	int x = 0;
	int y = 0;
	gets(input);
	for(int i = 0; i < strlen(input); i ++){
		if(input[i] == ';'){
			cur = i - 1;
			if((cur - last) == 1 ){
				dir = input[last];
				dis = input[cur] - '0';
				if(dis < 10)
				{
					
					move(dir, dis, &x, &y);
				}
			}
			if((cur - last) == 2 ){
				dir = input[last];
				dis = (input[cur - 1] - '0') * 10;
				if(dis < 100)
				{
					if(input[cur] - '0' < 10){
						dis += input[cur];
						move(dir, dis, &x, &y);
					}
				}
			}
			last = i + 1;
		}
	}
	printf("(%d,%d)",x,y);
	
	return 0;
}