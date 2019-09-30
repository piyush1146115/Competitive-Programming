#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1, h2, m1, m2, k, test, minute, time, mintime;
    int i, j;
//freopen("input.txt", "rt", stdin);
    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        scanf("%d %d:%d",&k, &h1, &m1);
        mintime = 1000000;
        h1 *= 60;
        h1 += m1;
        for(j = 1; j <= k; j++){
            scanf("%d:%d %d", &h2, &m2, &minute);

            h2 *= 60;
            h2 += m2;
         if(h1 > h2){
            time = 1440 - h1 + h2;
         }
         else
            time = h2 - h1;

            time += minute;

            //printf("%d\n",time);
            mintime = min(mintime , time);
        }

        printf("Case %d: %d\n",i,mintime);
    }
    return 0;
}
/*
#include<stdio.h>
int main()
{
    freopen("input.txt", "rt", stdin);
int nCase,tCase;

scanf("%d", &nCase);
for(tCase=1;tCase<=nCase;tCase++)
{
int k,cth,ctm,tcm,i,j,sum,min=10000000;
scanf("%d %d:%d",&k,&cth,&ctm);
tcm=(cth*60)+ctm;
for(i=1;i<=k;i++)
{
int ath,atm,tt,tam;
scanf("%d:%d %d",&ath,&atm,&tt);
tam=(ath*60)+atm;
if(tam<tcm)
sum=1440-tcm+tam+tt;
else
sum=tam-tcm+tt;
if(min>sum)
min=sum;
}
printf("Case %d: %d\n",tCase,min);
}
return 0;
}
*/
