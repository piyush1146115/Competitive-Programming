#include<bits/stdc++.h>
using namespace std;
int main()
{
    char num[10000], sign;
    long long div, n, m, ans[10000], rem;

    while(scanf("%s %c %lld",num, &sign, &div) == 3){
        int len = strlen(num), i, j;
        n = 0;
        m = 0;
        for(i = 0; i < len; i++){
            n = (num[i] - '0') + (n * 10);
            //printf("%lld\n", n);
            ans[m++] = n / div;
            rem = n % div;
           n = n % div;
        }
    int flag = 0;
        if(sign == '/'){
            for(i = 0; i < m ; i++){
            if(ans[i] != 0)
                flag = 1;

                if(flag)
                printf("%lld", ans[i]);
            }
            if(!flag)
                printf("0");

            printf("\n");
        }
        else
            printf("%lld\n", rem);
    }
    return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include <queue>
#include <vector>
#include<algorithm>
#include<iostream>
#define ll long long
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
using namespace std;
char res[100000];

void dev(char s[],long long int n)
{
    long long int rem=0,i,j=0;
    char a[100000];
    int f=1;
    for(i=0;i<strlen(s);i++)
    {
        rem=s[i]-'0'+rem*10;
        if(rem/n!=0)
        f=0;
        if(!f)
        printf("%lld",rem/n);
        rem=rem%n;
    }
    if(f)
    printf("0");
}

int rem(char s[],long long int n)
{
   long long  int i,rem=0,j;
    for(i=0;i<strlen(s);i++)
    {
        rem=s[i]-'0'+rem*10;
        rem=rem%n;
    }
    return rem;
}
int main()
{
    char s[100000],t;;
    long long int i,j,k,l,m,n;
    while(scanf("%s %c %lld",&s,&t,&n)==3)
    {
        if(t=='/')
        {
            dev(s,n);
            printf("\n");
        }

        else
        {
            m=rem(s,n);
            printf("%lld\n",m);
        }
    }
    return 0;
}
*/

