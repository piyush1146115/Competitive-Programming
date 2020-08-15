#include<stdio.h>
float comp(int ara[1005],float avg, int total)
{
    int a, b = 0;
    float  per,c;
    for(a = 0;a < total; a++){
        if (ara[a] > avg){
            b++;
        }
    }
   c = b*100;
   per = c/total;
   return per;

}
int main()
{
    int ara[1005];
    int total,a, b,sum,test;
    float avg,per;

    scanf("%d",&test);

    for(b = 1;b <= test; b++){

    scanf("%d",&total);//total students
    sum = 0;
    for(a = 0;a < total;a++){
        scanf("%d",&ara[a]);
        sum = sum + ara[a];
    }
    avg = sum/total;
    per = comp(ara,avg,total);

    printf("%.3f%%\n",per);
    }

    return 0;
}
