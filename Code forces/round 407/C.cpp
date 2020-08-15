#include<bits/stdc++.h>
using namespace std;
long long ara[1000005];
vector<long long> v;

int main()
{
    long long n;

    scanf("%lld", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", &ara[i]);

    for(int i = 0; i < n - 1; i++){
        v.push_back(abs(ara[i] - ara[i + 1]));
    }

    int cnt = -1;
    long long ans = -1, sum = 0;
    for(int i = 0; i < v.size(); i++){
            cnt++;
        if(cnt % 2 == 0){
            sum += v[i];
            ans = max(sum, ans);
        }
        else{
            sum -= v[i];
            if(sum < 0){
                cnt = -1;
                sum = 0;
            }
        }
    }
    cnt = -1;
    sum = 0;

       for(int i = 1; i < v.size(); i++){
            cnt++;
        if(cnt % 2 == 0){
            sum += v[i];
            ans = max(sum, ans);
        }
        else{
            sum -= v[i];
            if(sum < 0){
                cnt = -1;
                sum = 0;
            }
        }
    }
        printf("%lld\n",ans);

}
