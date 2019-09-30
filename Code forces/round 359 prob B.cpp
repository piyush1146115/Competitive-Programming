#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ara[105], i, j, k;
    vector <int> v[3];

    cin >> n;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&ara[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if((j - i) %2 == 0)
            {
                break;
            }
            if(ara[i] > ara[j])
            {
                v[0].push_back(i + 1);
                v[1].push_back(j + 1);
                for(k = i; k < j; k++)
                    swap(ara[k],ara[k+1]);
                i = -1;
                break;
            }
        }
    }

    for(i = 0; i < v[0].size(); i++)
        printf("%d %d\n",v[0][i], v[1][i]);

    return 0;

}
