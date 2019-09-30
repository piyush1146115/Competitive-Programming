#include<stdio.h>
int main()
{
    int m, n, c, a, b, d, temp, i = 0, j, sum;
    int con[21], state[100],flag[21],i_sum;

    while(scanf("%d %d %d", &n, &m, &c) == 3 && (n!= 0 && m != 0 && c != 0) ){
                sum = 0;
                i_sum = 0;
                i++;

            for( a = 0; a < n; a++){
                scanf("%d", &con[a]);
                flag[a] = 0;
            }
            for(d = 0; d < m; d++){
                scanf("%d", &state[d]);

                    if(flag[state[d] - 1]== 0){
                sum = sum + con[state[d] - 1];
                flag[state[d] - 1] = 1;
                    }
                  else{
                        sum = sum - con[state[d] - 1];
                        flag[state[d] - 1] = 0;
                    }
                if(i_sum < sum)
                    i_sum = sum;

            }

                  if(i_sum > c){
                    printf("Sequence %d\nFuse was blown.\n\n",i);
                }
                else{
                printf("Sequence %d\nFuse was not blown.\nMaximal power consumption %d amperes.\n\n",i, i_sum );
                }
    }


return 0;
}

