#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

string a, b;

ll ans[12];

ll dp[12][3][3][3][12][12];

ll fun(int pos, int isLow, int isHigh, int isStart, int num, ll cnt) {
    if (pos == 10) {
        return cnt;
    }
    int lo = 0, hi = 9;
    if (isLow == 0) {
        lo = b[pos] - '0';
    }
    if (isHigh == 0) {
        hi = a[pos] - '0';
    }
	
    ll &ret = dp[pos][isLow][isHigh][isStart][num][cnt];
    ll  n_cnt = cnt;
    if(ret != -1){
		return ret;
	}
    ret = 0;
    for(int i = lo; i <= hi; i++){
        n_cnt = cnt;
        if ((isStart||i > 0) && (i == num)){
            n_cnt = cnt + 1;
        }
       ret += fun(pos+1, isLow||(i > lo), isHigh||(i < hi), isStart||(i > 0), num, n_cnt);
    }
    return ret;
}

int main() {

    ll lo, hi;
        
    while (scanf("%lld %lld", &lo, &hi) == 2) {
        if (lo == 0 && hi == 0) {
            break;
        }

        if (hi < lo)
            swap(hi, lo);

        string temp = "";

        while (lo != 0) {
            b.push_back((char)(lo % 10 + '0'));
            lo /= 10;
        }

        int dif = 10 - (int)b.size();
        reverse(b.begin(), b.end());

        while (dif--) {
            temp.pb('0');
        }
        b = temp + b;
        while (hi != 0) {
            a.pb((char)(hi % 10 + '0'));
            hi /= 10;
        }
        //cout << a << endl;
        reverse(a.begin(), a.end());
        dif = 10 - (int)a.size();
        temp.clear();
        while (dif--) {
            temp.pb('0');
        }
        a = temp + a;
		memset(dp, -1, sizeof(dp));
        //cout << a << " " << b << endl;
        ll ret = fun(0, 0, 0, 0, 0, 0);

        printf("%lld", ret);

        for (int i = 1; i < 10; i++) {
			memset(dp, -1, sizeof(dp));
            ret = fun(0, 0, 0, 0, i, 0);
            printf(" %lld", ret);
        }
        printf("\n");

        a.clear();
        b.clear();
    }
}
