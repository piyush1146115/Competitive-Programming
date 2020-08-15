#include<bits/stdc++.h>
using namespace std;
map<long long , int> mp;
vector<long long int> v;
int main()
{
    long long k, n, i, j, sum = 0, m;

    scanf("%lld %lld", &m, &n);

    for(i = 0; i < m; i++){
        scanf("%lld", &j);
        mp[j]++;
    }
long long int co = 0;

    for(i = 1; ; i++){
        if(mp[i]  == 0){
                if(sum + i > n)
                break;

            sum += i;
            co++;
            v.push_back(i);
        }
    }

    printf("%lld\n", co);

    for(i = 0; i < v.size(); i++)
        printf("%lld ",v[i]);

    printf("\n");
}
