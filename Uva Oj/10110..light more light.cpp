#include<stdio.h>
#include<math.h>
int main()
    {
        unsigned long long n, a;
        double sq;
    while(scanf("%llu",&n) == 1 && n != 0){
        sq = sqrt(n);
        //printf("%lf ",sq);
        if(sq == (int)sq){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }

    return 0;
}
