#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, sqr, i ,j, k,count;
    float p;
    while(scanf("%d %d", &a, &b) == 2 &&(a != 0 || b != 0)){
        count = 0;
        for(i = a; i <= b; i++){
            p = sqrt(i);
            k = (int)p;
            //printf("%f\n",p);
            if(k == p)
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
