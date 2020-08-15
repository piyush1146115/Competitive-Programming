#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
   ll n, k;

    scanf("%I64d %I64d",&n, &k);

    while(n--){
        ll r, c;
//        cin >> r >> c;
        scanf("%I64d %I64d", &r, &c);
        ll dif = (r - 1) + (c - 1);
        int flag = 0;

        if(dif % 2 == 1)
            flag = 1;

        ll dd = min(r, c);
        dd--;

        ll div = dd/k;
        ll rx = 1 + (div * k);
        ll ry = 1 + (div * k);
       // cout << rx << " " << ry << endl;

        dif = (r- rx) + (c - ry);
        if(dif % 2 == 0 && div % 2 == 1)
            flag = 1;
        if(dif % 2 == 1 && div % 2 == 0)
            flag = 1;
        if(col <= 2){

        }
        if(flag)
            printf("+\n");
        else
            printf("-\n");
    }
}
