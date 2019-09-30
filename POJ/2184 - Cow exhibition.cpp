#include<bits/stdc++.h>
using namespace std;
#define mxx 105
#define pii pair<int, int>
#define MP make_pair
#define inf 1000000
#define ss second
#define ff first
#define DEBUG(x) cout << #x <<": " << x << endl

map< pii, pii > mp;

int funn[mxx], smart[mxx];
int n;

pii fun(int pos, int smartness)
{
//    DEBUG(pos);
//    DEBUG(smartness);

    if(pos == n)
        return MP(0,smartness);
//    if(mp.find(MP(pos, smartness)) != mp.end())
//        return mp[MP(pos, smartness)];

    pii temp1, temp;

    temp = fun(pos + 1, smartness);
    temp1 = fun(pos + 1, smartness + smart[pos]);
     temp1.ff += funn[pos];

    pii ans = MP(-inf, -inf);

    if(temp.ss >= ans.ss && temp.ss >= 0)
    {
        ans = temp;
    }
    if(temp1.ss >= 0 && temp1.ss >= ans.ss)
    {
        ans = temp1;
    }

//    DEBUG(pos);
//    DEBUG(temp.ff);
//    DEBUG(temp.ss);
//    DEBUG(temp1.ff);
//    DEBUG(temp1.ss);
//    DEBUG(ans.ff);
//    DEBUG(ans.ss);
        return ans;
    }

    int main()
    {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &smart[i], &funn[i]);
        }

        pii ans = fun(0, 0);
        DEBUG(ans.ff);
        DEBUG(ans.ss);

        if(ans.ff >= 0 && ans.ss >= 0)
        {
            //cout << ans.ff << " " << ans.ss << endl;
            printf("%d\n", (ans.ff + ans.ss));
        }
        else
        {
            printf("0\n");
        }
        mp.clear();
    }
