#include<stdio.h>
#include<stdint.h>

#include<stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
int V[61][3];
int VP[61][3];
int DP[3200];
int main()
{
    int N,m,v,p,q;
    
    while(scanf("%d%d",&N,&m)!=EOF)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&v,&p,&q);
            if(q)
            {
                if(V[q][1])
                {
                    V[q][2]=v/10;
                    VP[q][2]=v*p;
                }
                else
                {
                    V[q][1]=v/10;
                    VP[q][1]=v*p;
                }
            }
            else
            {
                V[i][0]=v/10;
                VP[i][0]=v*p;
            }
        }
        int vpt=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=N/10;j>=V[i][0]&&V[i][0]!=0;j--)
            {
                 //情况1，只有主（默认情况）
                vpt=V[i][0];
                DP[j]=max(DP[j],DP[j-vpt]+VP[i][0]);
                //情况2，有附件1+主（附件2有没有不管）
                if(V[i][1]!=0)
                {
                    vpt=V[i][0]+V[i][1];
                    if(j>=vpt)
                    {
                        DP[j]=max(DP[j],DP[j-vpt]+VP[i][0]+VP[i][1]);
                    }
                }
                 
                if(V[i][2]!=0)
                {
                    //情况3，附件2+主
                    vpt=V[i][0]+V[i][2];
                    if(j>=vpt)
                    {
                        DP[j]=max(DP[j],DP[j-vpt]+VP[i][0]+VP[i][2]);
                    }
                    //情况4，附件1+附件2+主
                    vpt=V[i][0]+V[i][2]+V[i][1];
                    if(j>=vpt)
                    {
                        DP[j]=max(DP[j],DP[j-vpt]+VP[i][0]+VP[i][2]+VP[i][1]);
                    }
                }
                
            }
        }
        printf("%d",DP[N/10]);
    }
    return 0;
}