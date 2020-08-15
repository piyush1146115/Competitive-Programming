#include<bits/stdc++.h>
using namespace std;
int  x[100000];
int main()
{
    int n, i, j, q, m, k;
    vector<int> v1, v2;
    map<int, int> mp;

    scanf("%d", &n);

    for(i = 0; i < n ; i++){
        scanf("%d", &x[i]);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++){
        scanf("%d", &j);
        v1.push_back(j);
    }
    v2 = v1;
    sort(x, x + n);
    sort(v1.begin(), v1.end());
    j = 0;

    for(i = 0; i < m ; i++){
        while(j < n){
            if(x[j] > v1[i]){
                break;
            }
            j++;
        }
        //printf("%d\n", j);
        mp[v1[i]] = j;
    }

    for(i = 0; i < m; i++){
        printf("%d\n", mp[v2[i]]);
    }

    return 0;
}

///angkur vai solution
/*
#include<bits/stdc++.h>
using namespace std;
int arr[100009];
int main()
{
    int i,j,n,m,a,b,k;
    scanf("%d",&k);
    for(i=0;i<k;i++)
        {
            scanf("%d",&arr[i]);
        }
    sort(arr,arr+k);
    int q,val;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&val);
        int res=upper_bound(arr,arr+k,val)-arr;
        printf("%d\n",res);
    }
    return 0;
}
*/
