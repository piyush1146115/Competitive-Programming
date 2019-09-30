#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    map <int, int> m;
    int n, i, j;

    while(scanf("%d",&n) == 1){
            int flag = 1;
        for(i = 0; i < v.size(); i++){
            if(v[i] == n)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        v.push_back(n);
        m[n]++;
    }

        for(i = 0; i < v.size(); i++){
               printf("%d %d\n",v[i], m[v[i]]);
            }

    return 0;
}
