#include<bits/stdc++.h>
using namespace std;
#define mxx 12

int dp[(1 << 12) + 5];

int Set(int n, int pos)
{
    return n = n | (1 << pos);
}

int reset(int n, int pos)
{
    return n = n & ~(1 << pos);
}

bool check(int n, int pos)
{
    return (bool)(n & (1 << pos));
}

int call(int mask)
{
   int ret =__builtin_popcount(mask);

   for(int i = 0; i < 11; i++){
    if(check(mask, i) == 1 && check(mask, i + 1) == 1){
        int temp = mask;
        temp = reset(mask, i);
        temp = reset(temp, i + 1);
        if(i > 0 && check(mask,i - 1) == 0){
            ret = min (ret, call(Set(temp, i - 1)));
        }
        if(i < 10 && check(mask, i + 2) == 0)
            ret = min(ret, call(Set(temp, i + 2)));
    }
   }
   return ret;
}

int main()
{
    int test;
    scanf("%d", &test);
    char str[15];
    while(test--)
    {

        scanf("%s",str);
        memset(dp, -1, sizeof(dp));
        int mask = 0;

        for(int i = 0; i < 12; i++)
        {
            if(str[i] == 'o')
            {
                mask = Set(mask, i);
            }
        }
        int ans = call(mask);
        printf("%d\n",ans);
    }

}

