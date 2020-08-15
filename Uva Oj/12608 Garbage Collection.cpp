#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N, W, we[1005], d[1005], i, j, w, sum;
    int test;

    cin >> test;

    while(test--){
        cin >> W >> N;

        for(i = 1; i <= N; i++)
            scanf("%lld %lld",&d[i], &we[i]);

        i = 1;
        w = 0;
        sum = 0;
        while(i <= N){
            if(w + we[i] == W){
                w = 0;
                sum += (d[i] * 2);
                i++;
                continue;
            }
            else if(w + we[i] > W ){
                w = 0;
                sum += (d[i] * 2);
                continue;
            }
            else if(i == N){
                sum += (d[i] * 2);
                i++;
                continue;
            }
             else if(w + we[i] < W && i != N){
                w += we[i];
                i++;
                continue;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
