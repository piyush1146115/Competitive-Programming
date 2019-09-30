#include<stdio.h>
#include<string.h>

float func(float n)
{
    int i, j, k, sum;

    j = n;

    while(j >= 10){
        sum = 0;
        i = j;
        while(i >= 1){
            k = i % 10;
            sum += k;
            i = i/10;
        }
        j = sum;
    }
    return j;
}
int main()
{
    int a, b;
    float c, d, i, j, k, rat, l1, l2, sum;
    char str[50], st2[50];

    while(gets(str)){
    gets(st2);

    l1 = strlen(str);
    l2 = strlen(st2);
    sum = 0;
    for(a = 0; a < l1; a++){
        if((str[a] >= 'a' && str[a] <= 'z') || (str[a] >= 'A' && str[a] <= 'z')){
            if(str[a] > 96){
                sum = sum + (str[a] - 96);
            }
            else
                sum += (str[a] - 64);
        }
    }
    c = func(sum);

    sum = 0;
     for(a = 0; a < l2; a++){
        if((st2[a] >= 'a' && st2[a] <= 'z') || (st2[a] >= 'A' && st2[a] <= 'z')){
            if(st2[a] > 96){
                sum = sum + (st2[a] - 96);
            }
            else
                sum += (st2[a] - 64);
        }
    }
    d = func(sum);

    if( c >= d){
        rat = d / c;
    }
    else{
        rat = c /d;
    }
    printf("%.2f %%\n",rat*100);
    }
    return 0;
}
