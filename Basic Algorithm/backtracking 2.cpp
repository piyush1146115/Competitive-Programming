#include<bits/stdc++.h>
using namespace std;
char s[] = "abc", ans[10];
int taken[10], flag[30];
int n = 3;

void gen(int idx)
{
    int i, j, k;

    if(idx == n)
    {
        for(i = 0; i < n ; i++)
        {
            printf("%c ",ans[i]);
        }

        printf("\n");
        return;
    }

    for(i = 0; i < n; i++)
    {
        //int xx=s[i]-'a';
        if(taken[i] == 0){
            taken[i] = 1;
            ans[idx] = s[i];
            gen(idx + 1);
            taken[i] = 0;
        }

    }
}


int main()
{
    //memset(rep,0,sizeof (rep));
    gen(0);


}
