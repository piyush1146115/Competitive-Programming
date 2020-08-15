#include<bits/stdc++.h>
using namespace std;
int print[10000];
int convert(int n)
{
    int b=0, i=0;
    if ((n%2)==0)
    {
        b=0;
    } else {
        b=1;
    }
    //cout << b ;
    print[i++]=b;
    while (n)
    {
        n-=b;
        n/=(-2);
        if ((n%2)==0)
        {
            b=0;
        } else
        {
            b=1;
        }
        //cout << b;
        print[i++]=b;
    }
    //cout << endl;
    return i;
}

int main()
{
    int n, i, kase=1, test;
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d",&n);
        if (n==0)
        {
            printf("Case #%d: 0\n",kase++);
            continue;
        }
        printf("Case #%d: ",kase++);
        i = convert(n)-2;
        for ( ; i>=0 ; i--)
        {
            printf("%d",print[i]);
        }
        printf("\n");
    }
    return 0;
}
