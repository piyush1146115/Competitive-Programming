#include<bits/stdc++.h>

using namespace std;

int main()
{
    int in, a, b, c, angle, sum;

    while(scanf("%d %d %d %d",&in, &a, &b, &c) == 4 && (in != 0 || a != 0 || b != 0 || c != 0)){
            sum = 0;
       if(a > in){
        sum += (40 -a) + in;
       }
       else{
        sum += (in - a);
       }
       if(b < a){
        sum += (40 - a) + b;
       }
       else{
        sum += (b - a);
       }
       if(c > b){
        sum += (40 - c) + b;
       }
       else{
        sum += (b - c);
       }

        angle = (sum * 9)  + 1080;

        printf("%d\n",angle);
    }
    return 0;
}
