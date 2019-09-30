#include<bits/stdc++.h>
using namespace std;
long long ara[10000000];

int main()
{
    long long n, i, j, k, test = 0, m;

    //scanf("%lld", &test);

    while(scanf("%lld", &n) , n){

        set<long long> s;
        int flag = 1;
        long long sq = sqrt(n);
        m  = 0;

        for(i = 1; i <= sq; i++){
            if(n % i == 0){
                   // flag =0;
                ara[m++] = i;
                if(n / i > 1000000)
                    continue;

                ara[m++] = n / i;
            }
        }

        printf("Scenario %lld:\n",++test);

           // set<long long> :: iterator it;


            /*for(it = s.begin(); it != s.end(); it++){
                //printf("%lld",*it);
                ara[m++] = *it;
            }*/
            sort(ara, ara + m);

            for(i = 0; i < m - 2; i++){
                for(j = i + 1; j < m -1; j++){
                        if(ara[j] - ara[i] > 25)
                        break;
                    for(k = j + 1; k < m; k++){
                        if(ara[k] -ara[i] > 25)
                        break;
                        flag = 0;
                    printf("%lld %lld %lld\n",ara[i],ara[j],ara[k]);
                    }
                }
            }

        if(flag){
            printf("Such bells don't exist\n");
        }
        printf("\n");
    }
}
