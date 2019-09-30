#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        v.push_back(m);
    }

    for(int i = 1; i < v.size(); i++){
        v[i] += v[i - 1];
    }
    vector<int> :: iterator it;

    int q;
    scanf("%d", &q);

    for(int i = 1; i <= q; i++){
            int p;
    scanf("%d", &p);
    it = lower_bound(v.begin(), v.end(), p);
    int res = it - v.begin();
    printf("%d\n", res + 1);

    }
}
