#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int i, j, k, l, m, n, flag = 0;

    cin >> n >> m >> k;

     l = m;
    for(i = 0; i < n; i++){
        scanf("%d",&j);
        v.push_back(j);
    }


    sort(v.begin(), v.end());
    int c1 = 0, c2 = 0;
    i = v.size() - 1;
    if(m <= k){
        flag = 1;
    }
    else{
        m  -= v[i];
    i--;
    k--;
    c1++;

    while(1){
       if(m <= k){
        flag = 1;
        break;
       }
       c1++;
       m -= (v[i] - 1);
       i--;
       if(i < 0)
        break;
    }
    k++;
    i = v.size() - 1;
    while(l > k){
        l -= v[i];
        c2++;
        i--;
        k--;
        if(i < 0 || k < 0)
            break;
    }
    if(l > k){
        c2 = 100;
    }
    else{
        flag = 1;
    }
    }
    if(flag == 0){
        printf("-1");
    }
    else{
        printf("%d\n",min(c1, c2));
    }

    return 0;
}
