#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b, s, i, j, cse = 0;
    vector <int> v;

    while(scanf("%d %d", &b, &s) == 2){
        cse++;
        if(b == 0 && s == 0)
            break;

        for(i = 0; i < b; i++){
            scanf("%d",&j);
            v.push_back(j);
        }
        for(j = 0; j < s; j++){
            scanf("%d", &i);
        }
        int dif = b - s;

        if(dif > 0){
                sort(v.begin(), v.end());
            printf("Case %d: %d %d\n",cse, dif, v[0]);
        }
        else
            printf("Case %d: 0\n", cse);

            v.clear();
    }
    return 0;
}
