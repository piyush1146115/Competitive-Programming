#include<bits/stdc++.h>
using namespace std;
#define mxx 20005

int cum[mxx], ara[mxx];

struct st
{
    int fin, beg;
};
st s;
vector<st> v;

bool comp(st a, st b)
{
    if((a.fin - a.beg) == (b.fin - b.beg)){
        return a.beg < b.beg;
    }
    else{
        return (a.fin - a.beg) > (b.fin - b.beg);
    }
}

int n;

int main()
{
    int tc = 0;
    int test;
    scanf("%d", &test);

    while(test--){

            scanf("%d", &n);
            int sum = 0, ans = 0;

        for(int i = 1; i < n; i++){
            scanf("%d", &ara[i]);
            sum += ara[i];
            if(sum == 0){
                cum[i] = -1;
                continue;
            }
            if(sum < 0){
                sum = 0;
            }
            cum[i] = sum;
            ans = max(ans, sum);
        }

        if(ans <= 0){
            printf("Route %d has no nice parts\n",++tc);
        }
        else{
            for(int i = n - 1; i >= 1; i--){
                if(cum[i] == ans){
                    s.fin = i + 1;
                    for(int j = i; j >= 1; j--){
                        if(cum[j] == 0){
                            s.beg = j + 1;
                            i = j + 1;
                            break;
                        }
                        if(j == 1){
                            s.beg = 1;
                            i = j;
                            break;
                        }
                    }
                    v.push_back(s);
                }
            }

            sort(v.begin(), v.end(), comp);

            printf("The nicest part of route %d is between stops %d and %d\n",++tc, v[0].beg, v[0].fin);
//            if(test)
//                printf("\n");
        }

        v.clear();
    }
}
