#include<bits/stdc++.h>
using namespace std;
long long ar[100000];
int main()
{
    long long n, k, i, j;
    set<long long> s;
    vector<long long> v;
    scanf("%lld %lld",&n, &k);
if(k == 1){
    printf("%lld\n", n);
}
else{
    for(i = 0; i < n; i++){
        scanf("%lld",&ar[i]);
    }

    sort(ar, ar+ n);

    for(i = 0; i < n; i++){
        if(ar[i] % k == 0){
        j = ar[i] / k;
        if(s.count(j) == 0){
            v.push_back(ar[i]);
            s.insert(ar[i]);
        }
        }
        else{
            v.push_back(ar[i]);
            s.insert(ar[i]);
        }
    }

    printf("%d\n",v.size());
}
}
