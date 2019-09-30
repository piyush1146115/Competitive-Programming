#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;

    scanf("%d", &n);

    printf("%d:\n",n);
    for(int i = 2; i < n ; i++){
        int ff = i;
        int ss = i - 1;
        int sum = (ff + ss);

        if((n % sum == 0) || (n % sum == ff)){
            printf("%d,%d\n",ff,ss);
        }
        if(n % ff == 0){
            printf("%d,%d\n",ff,ff);
        }
    }
}
