#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d %d",&n, &k);
    int ara[n + 10];

    for(int i = 0 ; i < n; i++)
        scanf("%d",&ara[i]);

    vector<int> vec, v;

    for(int i = 0; i < k; i++){
        int m;
        scanf("%d",&m);
        v.push_back(m);
    }

    sort(v.begin(), v.end());

    int j = v.size() - 1;

    for(int i = 0; i < n; i++){
        if(ara[i] != 0)
            vec.push_back(ara[i]);
        else
        {
            vec.push_back(v[j]);
            j--;
        }
    }

    vector<int> temp;
    temp = vec;
    sort(vec.begin(), vec.end());

    if(vec != temp){
        printf("Yes\n");
    }
    else
        printf("No\n");
}
