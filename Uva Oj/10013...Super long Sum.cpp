#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000 + 5
int num1[MAX];
int num2[MAX];
int res[MAX];


int main()
{
    long long sum, indx, carry, m, test, i, j;

    scanf("%lld", &test);

    while(test--){

        scanf("%lld", &m);

        for(i = 0; i < m; i++){
            scanf("%d %d", &num1[i], &num2[i]);
        }
        carry = 0;
        indx = 0;
        for(i = m - 1; i >= 0; i--){
            sum = num1[i] + num2[i] + carry;

            if(sum < 10){
                carry = 0;
                res[indx++] = sum;
            }
            else{
                carry = sum / 10;
                j = sum - (carry * 10);
                res[indx++] = j;
            }
        }
        if(carry != 0)
            res[indx++] = carry;

      for(i = indx - 1; i >= 0; i--)
        printf("%d",res[i]);

      printf("\n");

      if(test)
        printf("\n");
    }
    return 0;
}
