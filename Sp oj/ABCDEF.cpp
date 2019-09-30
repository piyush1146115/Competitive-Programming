#include<bits/stdc++.h>
using namespace std;

int lft[1000005], rgt[1000005];


int lbound(int key, int mx)
{
    int hi, lo, mid;

    lo = 0, hi = mx - 1;

    while(lo <= hi){
        mid = (lo + hi) / 2;

        if(rgt[mid] == key){
            hi = mid - 1;
        }
        else if(rgt[mid] > key){
            hi = mid - 1;
        }
        else{
            lo = mid +  1;
        }
    }

    return lo;

}

int ubound(int key, int mx)
{
    int hi, lo, mid;

    lo = 0, hi = mx - 1;

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(rgt[mid] == key){
            lo = mid + 1;
        }
        else if(rgt[mid] > key){
            hi = mid - 1;
        }
        else{
            lo = mid +  1;
        }
    }

    return lo;

}

vector<int>v;
int main()
{
    int i, j, k, l, m,val, idx = 0, n, id2 = 0;
    int ara[105];

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){
                val = (ara[i] * ara[j]) + ara[k];
                lft[idx++] = val;
            }
        }
    }

       for(i = 0; i < n; i++){
            if(ara[i] == 0)
            continue;

        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){
                val = ara[i] * (ara[j] + ara[k]);
                rgt[id2++] = val;
            }
        }
    }

    sort(rgt, rgt + id2);

    long long res = 0;


    for(i = 0; i < idx; i++){
        int lb = lbound(lft[i], id2);
        int ub = ubound(lft[i], id2);

        if(lb >= 0 && ub >= 0)
        res += (ub - lb);
    }

    printf("%lld\n",res);

    return 0;
}
