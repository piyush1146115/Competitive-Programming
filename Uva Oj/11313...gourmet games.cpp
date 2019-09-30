#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, count, i, j, test, flag;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        flag = 0;
        count = 0;
        while(n > 0){
            n = n - m + 1;
            count++;
            if(n == 1){
                break;
            }
            else if(n < m){
                flag = 1;
                break;
            }
        }
        if(flag){
            printf("cannot do this\n");
        }
        else{
            printf("%d\n",count);
        }
    }
    return 0;
}
