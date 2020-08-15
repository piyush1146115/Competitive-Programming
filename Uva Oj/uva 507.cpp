#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

pair<int, int> p[20005];

bool comp(pair<int, int> a, pair <int, int> b)
{
    if((a.ss - a.ff) == (b.ss - b.ff)){
        return a.ff < b.ff;
    }
    else return (a.ss - a.ff) > (b.ss - b.ff);
}

int ara[20005];

int main()
{
    int test, tc = 0, i;

    scanf("%d",&test);

    while(test--){
            int n;

        scanf("%d",&n);

        for(i = 1; i < n; i++){
            scanf("%d",&ara[i]);
        }
        int sum = 0, mxx = 0;

        for(i = 1; i < n; i++){
            sum += ara[i];
            if(sum < 0)
                sum = 0;

            mxx = max(sum, mxx);
        }

        int start = -1, last;

        if(mxx != 0){
        sum = 0;
        int ind = 0;

        for(i = 1; i < n; i++){
            sum += ara[i];

            if(start == -1){
                start = i;
            }

            if(sum < 0){
            sum = 0;
            start = i + 1;
            }

            if(sum == mxx){
                last= i + 1;
                p[ind].ff = start;
                p[ind].ss = last;
                ind++;
            }
        }

        //last++;
        sort(p, p + ind, comp);

        printf("The nicest part of route %d is between stops %d and %d\n", ++tc, p[0].ff, p[0].ss);
    }

    else{
        printf("Route %d has no nice parts\n", ++tc);
    }
    }

}
