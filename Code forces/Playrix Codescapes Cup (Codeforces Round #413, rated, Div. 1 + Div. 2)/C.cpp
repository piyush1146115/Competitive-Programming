#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 100005

struct st{
int beauty, price;
};

vector<st> v1, v2;
st s;

bool comp(st a, st b)
{
    if(a.beauty == b.beauty)
        return a.price < b.price;
    return a.beauty < b.beauty;
}

int main()
{
    int n, c, d;

    scanf("%d %d %d",&n , &c, &d);
    int p, b;
    char ch;
    for(int i = 0; i < n; i++){
        scanf("%d %d %c",&b, &p, &ch);
        s.beauty = b;
        s.price = p;

        if(ch == 'C'){
            if(p <= c){
                v1.push_back(s);
            }
        }
        else{
            if(p <= d){
                v2.push_back(s);
            }
        }
    }

    sort(v1.begin(), v1.end(), comp);
    sort(v2.begin(), v2.end(), comp);

    int ans = -1;

    for(int i = 0; i < v1.size() - 1; i++){
    int lo = i + 1, hi = v1.size() - 1, mid;

        while(lo <= hi){
            mid = (lo + hi)/2;
            int cost = v1[i].price + v1[mid].price;
            if(cost <= c){
                lo = mid + 1;
                ans = max(ans, v1[i].beauty + v1[mid].beauty);
            }
        }

    }
}
