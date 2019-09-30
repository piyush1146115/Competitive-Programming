#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wt", stdout);
    long long int n, t, i, j, sum = 0, ara[60];
    multiset <long long int> m;
    int test, cse = 0;
    scanf("%d",&test);
    while(test--){
            cse++;
            scanf("%lld %lld",&n, &t);
        for(i = 0; i < n; i++){
            scanf("%lld", &ara[i]);
        }
        sort(ara, ara + n);
        sum = 0;
        for(i = 0; i < n; i++){
            if(sum + ara[i] < t){
                m.insert(ara[i]);
                sum += ara[i];
            }
            else{
                int s;
                multiset<long long int>::iterator it;
                if(!m.empty()){
                    for(it = m.begin(); it != m.end(); it++){

                        s = (sum - *it) + ara[i];
                        if(s > sum && s < t){
                            sum -= *it;
                            sum += ara[i];
                            m.erase(it);
                            m.insert(ara[i]);
                        }
                    }
                }
            }
        }
        printf("Case %d: %d %lld\n", cse, m.size() + 1, sum + 678);
        m.clear();
    }
    return 0;
}
