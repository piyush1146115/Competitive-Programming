#include<bits/stdc++.h>
using namespace std;
class terror{
public:
    long long x, y;
};

   bool comp(terror a, terror b){
    return (a.y - a.x) > (b.y - b.x);
    }
terror ara[1000005];
int main()
{
    int n, k, i, j, test, cs = 0;

        scanf("%d", &test);

        while(test--){
            scanf("%d %d", &n, &k);
            if(k >=  n){
                k = n;
            }
            for(i = 0; i < n; i++){
                scanf("%lld",&ara[i].x);
            }
             for(i = 0; i < n; i++){
                scanf("%lld",&ara[i].y);
            }
            sort(ara, ara + n, comp);
            long long sum = 0;

            for(i = 0; i < n - k; i++){
                sum += (ara[i].y - ara[i].x);
                //cout << ara[i].y << " " << ara[i].x << endl;
            }


            for(i =n - k; i < n; i++){
                if(ara[i].y > ara[i].x){
                    sum += (ara[i].y - ara[i].x);
                }
            }

            printf("Case %d: ",++cs);
            if(sum > 0){
                printf("%lld\n",sum);
            }
            else{
                printf("No Profit\n");
            }
        }
        return 0;
}
