#include<bits/stdc++.h>
using namespace std;
int  ara[100005];
int main()
{
    int n, i, j, k;

    cin >> n;
    for(i = 0; i < n; i++){
        scanf("%d",&ara[i]);
    }
    int c1= 0, c2 = 0, s = 0, a = 0, b = 0;
    i = 0;
    j = n - 1;
    while(i <= j){
        if(a <= b){
            c1++;
            a += ara[i];
              i++;
        }
        else{
                c2++;
            b += ara[j];
               j--;
        }


    }
 printf("%d %d\n",c1, c2);
}
