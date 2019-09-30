#include<bits/stdc++.h>
using namespace std;
int ara[200005];
int main()
{
    string s;
    cin >> s;

    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        int num = s[i] - '0';
        ara[i] = num % 3;
    }

    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(ara[i]== 0)
        {
            cnt++;
            sum = 0;
        }
        else
        {

            if((i + 1) < n && (ara[i] + ara[i + 1]) % 3 == 0 && ara[i + 1] != 0)
            {
                sum = 0;
                i++;
                cnt++;
                continue;
            }
            if((i + 2) < n && (ara[i] + ara[i + 1] + ara[i + 2]) % 3 == 0 && ara[i + 1] != 0 && ara[i + 2] != 0)
            {
                sum = 0;
                i += 2;
                cnt++;
                continue;
            }
        }
    }

    printf("%d\n",cnt);

}
