#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std ;
int main()
{
    long long int head[20005], knight[20005];
    long long int m, n, status, i, j, k, a, sum;

    while(scanf("%lld %lld", &n ,&m) == 2  && (m != 0 || n != 0)){
            status = 0;
        for( i = 0; i < n; i++){
            scanf("%lld",&head[i]);
        }

        for(i = 0; i < m; i++){
            scanf("%lld",&knight[i]);

        }

        if(m < n){
            printf("Loowater is doomed!\n");
        }
        else{
            sort(knight, knight + m);
            sort(head, head + n);

            sum = 0;
             a = 0;
            for(i = 0; i < n; i++){

                for(j = a; j < m; j++){
                    if(knight[j] >= head[i]){

                         sum += knight[j];
                            //printf("%d\n", head[i]);
                            a = j + 1;
                            break;
                        }
                }
                if(j == m){
                    status = 1;
                    break;
                }
            }
            if(status == 1){
                printf("Loowater is doomed!\n");
            }
            else{
                printf("%lld\n",sum);
            }

        }
    }
    return 0;
}
