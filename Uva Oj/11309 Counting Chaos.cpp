#include<bits/stdc++.h>
using namespace std;

bool chk(int n){
int m, j, k;
m = n;
j = 0;
    while(n != 0){
        j = (n % 10) + (j * 10);
        n /= 10;
    }
    if(j == m)
        return true;
    else
        return false;
}
int main()
{
   // freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    int test, n, h, m, i, j;

    scanf("%d", &test);

    while(test--){
        scanf("%d:%d",&h,&m);

        n = (h * 100) + m;
         n += 1;
         h = n / 100;
         m = n % 100;
        if(h == 23 && m > 32){
            n = 0;
        }

             if(n % 100 >= 60){
            n += (100 - (n  % 100));
        }
         while(!chk(n)){
            n++;
             if(n % 100 >= 60){
            n += (100 - (n  % 100));
        }
         }

         printf("%02d:%02d\n", n / 100, n % 100);
    }
    return 0;
}
