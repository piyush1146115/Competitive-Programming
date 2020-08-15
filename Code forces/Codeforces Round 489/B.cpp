#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<long long> divv;


int main()
{
    long long  l, r, x, y, cnt = 0;

    cin >> l >> r >> x >> y;

    if(y % x != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        ll d = y / x;
        ///232 380232688 116 760465376
        ///39443 809059020 19716 777638472

        ll sq = sqrt(d);
        int cnt = 0;
        for(ll i = 1; i <= sq; i++)
        {
            if((d % i == 0) && (i*x >= l) && (i*x <= r))
            {
                ll temp = d / i;
                if( temp*x >= l && temp*x <= r)
                {
                    ll gc = __gcd(temp, i);
                    ll mul = temp * i;
                    if(gc == 1 && mul == d){
                        //cout << i << "  " << temp << endl;
                        if(i == temp)cnt++;
                        else cnt+=2;
                    }

                }
            }
        }
    cout << cnt << endl;
    }
}
