#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, r, c, r1, c1, dif1, dif2, mov, test, t, i, flag;
    int di[4][2] = {{+1, +1}, {-1, -1}, {+1, -1}, {-1, +1} };

    cin >> test;

    while(test--){

        scanf("%lld", &t);
        scanf("%lld", &n);
        while(t--){
                flag = 0;
            scanf("%lld %lld %lld %lld",&r, &c, &r1, &c1);
            if(r1 < 1 || r1 > n || c1 < 1 || c1 > n || r > n || c > n || r < 1 || c < 1){
                flag = 0;
            }
            else{
              dif1 = abs(r1 -r);
            dif2  = abs(c1 - c);
            if(dif1 == 0 && dif2 == 0){
                mov = 0;
                flag = 1;
            }
                else if(dif1 == dif2){
                    mov = 1;
                    flag = 1;
                }
                else{
                    if(dif1 % 2 == 0 && dif2 % 2 == 0){
                        mov = 2;
                        flag = 1;
                    }
                    else if(dif2 % 2 == 1 && dif1 % 2 == 1){
                        mov = 2;
                        flag = 1;
                    }
                }
            }
            if(flag == 0){
                printf("no move\n");
            }
                else
                    printf("%lld\n",mov);
            }
        /*if(test)
            printf("\n");*/
    }
    return 0;
}
