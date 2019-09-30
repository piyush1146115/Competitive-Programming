#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool chk[1050];

void sieve()
{
    chk[1] = 1;
    for(int i = 2;i <= 1040; i++){
        if(chk[i] == 0){
            prime.push_back(i);
        }
        for(int j = i + i; j <= 1040; j += i){
            chk[j] = 1;
        }
    }
}


int fun(int n)
{
    int sum = 1;

    for(int i = 0;prime[i]*prime[i] <= n; i++){
        int cnt = 0;
        while(n % prime[i] == 0){
            cnt++;
            n /= prime[i];
        }
        if(cnt){
            sum *= (cnt + 1);
        }
    }

    if(n > 1){
        sum *= 2;
    }

    return sum;
}


int main()
{
    sieve();
    int  I,J,K;

    scanf("%d %d %d", &I, &J, &K);
    long long ans = 0;
    map<int, int> mp;

    for(int i = 1; i <= I; i++){
        for(int j = 1; j <= J; j++){
            for(int k = 1; k <= K; k++){
                int mul = i*j*k;
                if(mp.find(mul) == mp.end()){
                    mp[mul] = fun(mul);
                }
                ans += mp[mul];
              //  cout << mul << " " << fun(mul) << endl;

            }
        }
        ans %= 1073741824;
    }

    printf("%I64d\n",ans);

}
