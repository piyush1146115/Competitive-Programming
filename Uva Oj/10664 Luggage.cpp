#include<bits/stdc++.h>
using namespace std;

int ara[25];
int tot, n = 0;

int fun(int pos, int sum)
{

    int p1 , p2;

    if(sum * 2 == tot)
        return 1;
    if((sum * 2) > tot)
        return 0;

    if(pos == n)
    return 0;

    p1 = p2 = 0;

    p1 = fun(pos + 1, sum);
    p2 = fun(pos + 1, sum + ara[pos]);

    return p1 | p2;

}

int main()
{
    string s;

    int test;

    scanf("%d", &test);
    getchar();

    while(test--){

       getline(cin, s);
        n = tot = 0;

        stringstream ss(s);

        while(ss >> ara[n]){
            n++;
        }
        for(int i = 0; i < n; i++)
           tot += ara[i];

    int ans =   fun(0, 0);

        if(ans == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
