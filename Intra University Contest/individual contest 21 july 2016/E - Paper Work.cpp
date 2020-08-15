#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0, con = 0, i, j, n, ara[105];
    vector<int> v;

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&ara[i]);
    }

    for(i = 0; i < n; i++){
        if(ara[i] < 0){
            con++;
        }
        sum++;

        if(con == 3){
            v.push_back(sum - 1);
            sum = 1;
            con = 1;
        }
    }

        v.push_back(sum);


    printf("%d\n",v.size());

    for(i = 0; i < v.size(); i++){
        printf("%d ",v[i]);
    }

    return 0;
}
