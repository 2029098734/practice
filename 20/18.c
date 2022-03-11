#include <stdio.h>
#include <string.h>
#include <ctype.h>
char repeat_code(char *s, int *record)
{
    if( !s ) return 0;
    
    int len = strlen(s), i = 0, j = 0, val = 0, idx = 0;
    while(i < len)
    {
        if( isdigit( s[i] ) ){
            val = val*10 + s[i]-'0';
        }
        else if(s[i] == '.'){
            if(j==i || idx==3 || i+1==len || val>255) return 0;
            record[ idx++ ] = val;
            val = 0;   j = i+1;
        }
        else return 0;
        ++i;
    }
    if(idx!=3 || val>255) return 0;
    record[3] = val;
    return 1;
}
char judge_mask(int *mask)
{
    unsigned val = 0;
    for(int i=0; i<4; ++i)
        val |= mask[i]<<(3-i)*8;
    return !(!val || val==0xFFFFFFFF || (val|val-1)!=0xFFFFFFFF);
}
int main(void)
{
    int ip[4], mask[4], cnt[5] = {0}, Err_cnt = 0, private_cnt = 0;
    memset(ip, -1, 4*sizeof(int));
    memset(mask, -1, 4*sizeof(int));
    char s[88];
    while(scanf("%s", s) != EOF)
    {
        int idx = 0;
        while(s[idx] && s[idx]!='~')
            ++idx;
        if( s[idx] ){
            s[idx] = '\0';
        }
        else{
            ++Err_cnt;   goto rpt;
        }
        char ip_flag = repeat_code(s, ip);
        char mask_flag = repeat_code(s+idx+1, mask);
        if(!ip[0] || ip[0]==127) goto rpt;
        if(!ip_flag || !mask_flag || !judge_mask(mask)){
            ++Err_cnt;   goto rpt;
        }
        
        if(ip[0] < 127){
            ++cnt[0];
            if(ip[0] == 10) ++private_cnt;
        }
        else if(ip[0] < 192){
            ++cnt[1];
            if(ip[0]==172 && ip[1]>=16 && ip[1]<=31) ++private_cnt;
        }
        else if(ip[0] < 224){
            ++cnt[2];
            if(ip[0]==192 && ip[1]==168) ++private_cnt;
        }
        else if(ip[0] < 240) ++cnt[3];
        else ++cnt[4];
        
rpt:    memset(ip, -1, 4*sizeof(int));
        memset(mask, -1, 4*sizeof(int));
    }
    
    printf("%d %d %d %d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], Err_cnt, private_cnt);
    return 0;
}