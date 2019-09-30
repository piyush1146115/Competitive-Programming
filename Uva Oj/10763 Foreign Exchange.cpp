#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> up, down;
    int n, p, q, i;

    while(scanf("%d", &n) == 1){
            if(n == 0)
            break;
        for(i = 0; i < n; i++){
            scanf("%d %d", &p, &q);
            up.push_back(p);
            down.push_back(q);
        }
        sort(up.begin(), up.end());
        sort(down.begin(), down.end());
        for(i = 0; i < n; i++){
            if(up[i] != down[i]){
                break;
            }
        }
        if(i == n)
            printf("YES\n");
        else
            printf("NO\n");

       up.clear();
       down.clear();
    }
    return 0;
}
