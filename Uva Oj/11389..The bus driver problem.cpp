#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, r, i, sum;
    int mor[105], eve[105];

    while(scanf("%d %d %d",&n, &d, &r) == 3 && (n != 0 || d != 0 || r != 0)){
        for(i = 0; i < n; i++ ){
            scanf("%d",&mor[i]);
        }

        for( i =0; i < n; i++){
            scanf("%d",&eve[i]);
        }
        sort(mor, mor + n);
        sort(eve, eve + n);
        sum = 0;
        for(i = 0; i < n; i++){
            if(mor[i] + eve[n - i - 1] > d){
                sum += (mor[i] + eve[n - i -1]) - d;
            }
        }

        printf("%d\n",sum * r);
    }
    return 0;
}
