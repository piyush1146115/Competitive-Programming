#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
struct st{
ll id, c, p;
}ara[MAX];
ll ans[MAX];
bool comp(st a, st b)
{
    return a.p < b.p;
}

int main()
{
    ll n, k;

    scanf("%I64d %I64d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%I64d", &ara[i].p);
        ara[i].id = i;
    }
    for(int i = 0; i < n; i++){
        scanf("%I64d", &ara[i].c);
    }

    sort(ara, ara+ n, comp);
    priority_queue<ll> pq;

    for(int i = 0; i < k; i++){
        pq.push(-1);
    }

    for(int i = 0; i < n; i++){
        vector<ll> temp;
        ll sum = ara[i].c, cnt = 0;

        while(cnt < k){
            cnt++;
            ll t = pq.top();
            if(t > -1){
                temp.push_back(t);
                sum += t;
                pq.pop();
            }
        }
        for(int j = 0; j < (int)temp.size(); j++){
            pq.push(temp[j]);
        }
        pq.push(ara[i].c);
        ans[ara[i].id] = sum;
        temp.clear();
    }

    for(int i = 0; i < n; i++){
        printf("%I64d ",ans[i]);
    }
    printf("\n");
}
