//PIYUSH

#include<bits/stdc++.h>
using namespace std;
int ara[5], ans[5];

bool test()
{
   sort(ans, ans + 4);
    int sum = 0;

    for(int i = 0; i < 4; i++){
        sum += ans[i];
    }

    if(sum % 4 != 0)
        return false;

        int y = sum / 4;
    int x = ans[1] + ans[2];

    if(2 * y != x)
        return false;

    if(y != (ans[3] - ans[0]))
        return false;

    return true;

}


int main()
{
    int n, i, j, k;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d",&ara[i]);

    sort(ara, ara + n);

    if(n == 0){
        printf("YES\n1\n2\n2\n3\n");
    }
    else if(n == 1){

        printf("YES\n");
        printf("%d\n%d\n%d\n",ara[0]*2, ara[0]*2, ara[0] * 3);
    }
    else if(n == 2){
        if(ara[1] == ara[0]*3){
            printf("YES\n");
            printf("%d\n%d\n",ara[0]*2, ara[0]*2);
        }
        else if(ara[1] == ara[0] * 2){
            printf("YES\n");
            printf("%d\n%d\n",ara[0] * 2, ara[0] * 3);
        }

        else if(ara[1] < ara[0] * 3){
            int x = 4*ara[0] - ara[1];
            if(x <  ara[0]){
                printf("NO\n");
            }
            else{
                printf("YES\n%d\n%d\n",x, ara[0] * 3);
            }
        }

        else
            printf("NO\n");

    }

    if(n == 3){
            int flag = 1;

        //cout << endl << endl;


            for(j = 1; j <= 100000; j++){

            for(i = 0; i < 3; i++)
                ans[i] = ara[i];

                ans[3] = j;


                if(test()){
                    printf("YES\n%d\n",j);
                    flag = 0;
                    break;
                }
            }

        if(flag)
            printf("NO\n");

    }

    if(n == 4){
        for(i = 0; i < 4; i++)
            ans[i] = ara[i];

        if(test()){
            printf("YES\n");
        }
        else
            printf("NO\n");
    }

    return 0;
}
