#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,flag;
    double dif, power, i, j;

    while(scanf("%d",&n) == 1 && n != 0){
            flag = 1;
        for(i = 2; i <= 60; i++){
            power = pow(i, 3);

            for(j = 1; j <= i; j++){
                dif = power - pow(j,3);
                if(dif == n){
                    printf("%.0lf %.0lf\n",i, j);
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
            if(i == 60)
                printf("No solution\n");
        }
    }
    return 0;
}
