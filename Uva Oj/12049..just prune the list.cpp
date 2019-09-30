#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i, j, n, m, test, li1[10005], li2[10005];
    map<long long int, int> m1, m2;
    set<long long int> s1, s2;
    cin >> test;

    while(test--){
        scanf("%lld %lld",&m, &n);

        for(i = 0; i < m; i++){
            scanf("%lld", &li1[i]);
            s1.insert(li1[i]);
            m1[li1[i]]++;
        }
        for(i = 0; i < n; i++){
            scanf("%lld",&li2[i]);
            s2.insert(li2[i]);
            m2[li2[i]]++;
        }
        int c = 0, d;

        set <long long> :: iterator it;
       for(it = s1.begin(); it != s1.end(); it++){
            d = (m1[*it] - m2[*it]);
            if(d > 0)
                c += d;
       }
        for(it = s2.begin(); it != s2.end(); it++){
             d = m2[*it] -m1[*it];
             if(d > 0)
                c += d;
        }
        printf("%d\n", c);
        m1.clear();
        m2.clear();
        s1.clear();
        s2.clear();
    }
return 0;
}
