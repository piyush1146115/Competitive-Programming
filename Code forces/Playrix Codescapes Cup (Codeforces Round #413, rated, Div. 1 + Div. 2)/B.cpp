#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 200005
#define inf 2000000

struct st{
ll price,  ori;
};

ll p[mxx], a[mxx], b[mxx];
st s;
bool flag[mxx];

vector<st> v1, v2, v3;

bool comp(st s1, st s2)
{
    if(s1.price < s2.price)
        return true;
    else
        return false;
}

int main()
{
    ll n;

    scanf("%I64d", &n);

    for(int i = 0; i < n; i++){
        scanf("%I64d", &p[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
    }


    for(int i = 0; i < n; i++){
        scanf("%I64d", &b[i]);
    }

    for(int i = 0; i < n; i++){
        s.price = p[i];
        s.ori = i;
        if(a[i] == 1 || b[i] == 1){
            v1.push_back(s);
        }
        if(a[i] == 2 || b[i] == 2){
            v2.push_back(s);
        }
        if(a[i] == 3 || b[i] == 3){
            v3.push_back(s);
        }
    }

    ll  p1 = 0, p2 = 0, p3 = 0;

    sort(v1.begin(), v1.end(), comp);
    sort(v2.begin(), v2.end(), comp);
    sort(v3.begin(), v3.end(), comp);

//    for(int i  = 0; i < v1.size(); i++){
//        cout << v3[i].ori << " " << v3[i].price << endl;
//    }

    ll m, c;

    scanf("%I64d", &m);

    while(m--){

        scanf("%I64d", &c);

        if(c == 1){
            ll get = 1;

            for(int i = p1; i < v1.size(); i++){
                if(flag[v1[i].ori] == 0){
                    get = 0;
                    flag[v1[i].ori] = 1;
                    printf("%I64d ",v1[i].price);
                    p1 = i;
                    break;
                }
            }
            if(get){
                printf("-1 ");
                p1 =  inf;
            }
        }
        else if(c == 2){
            ll get = 1;

            for(int i = p2; i < v2.size(); i++){
                if(flag[v2[i].ori] == 0){
                    get = 0;
                    flag[v2[i].ori] = 1;
                    printf("%I64d ",v2[i].price);
                    p2 = i;
                    break;
                }
            }
            if(get){
                printf("-1 ");
                p2 = inf;
            }
        }
        else if(c == 3){
            ll get = 1;

            for(int i = p3; i < v3.size(); i++){
                if(flag[v3[i].ori] == 0){
                    get = 0;
                    flag[v3[i].ori] = 1;
                    printf("%I64d ",v3[i].price);
                    p3 = i;
                    break;
                }
            }
            if(get){
                printf("-1 ");
                p3 = inf;
            }
        }
    }
    printf("\n");
}

