#include<bits/stdc++.h>
using namespace std;
int main()
{
   unsigned long long int n, up, down, r, c, k, i, j, dif;
    vector <unsigned long long int> num, den;

    while(scanf("%llu %llu",&n, &r) == 2){
        if(r > n  || (r == 0 && n == 0))
            break;

         dif = n - r;
        if(dif > r){
            for(i = n; i > dif; i--)
                num.push_back(i);

            for(i = 1; i <= r; i++)
                den.push_back(i);
        }
        else{
            for(i = n; i > r; i--)
                num.push_back(i);

            for(i = 1; i <= dif; i++)
                den.push_back(i);
        }


        down = 1;
        for(j = 0; j < den.size(); j++){
                int flag = 1;
            for(i = 0; i < num.size(); i++){
                if(num[i] % den[j] == 0){
                    num[i] /= den[j];
                    flag = 0;
                    break;
                }
            }
            if(flag)
                down *= den[j];
               // printf("%llu\n",down);
        }


        up = 1;
        for(i = 0; i < num.size(); i++){
            up *= num[i];
            //printf("%llu\n",up);
        }
        printf("%llu things taken %llu at a time is %llu exactly.\n", n,r, up/down);
        num.clear();
        den.clear();
    }
    return 0;
}
