#include<bits/stdc++.h>
using namespace std;
#define mp(x,y) make_pair(x, y)
#define ff first
#define ss second
int main()
{
pair<int, int> p[105];
int l, w, h, vol, t, i;

while(scanf("%d",&t) == 1 && t != 0){

    for(i = 0; i < t; i++){
        scanf("%d %d %d",&l, &w, &h);
        vol = l * w * h;
        p[i] = mp(h, vol);
    }
    sort(p, p + t);
    printf("%d\n",p[t - 1].ss);
}
return 0;
}
