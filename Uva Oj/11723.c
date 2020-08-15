#include<stdio.h>
int main()
{
    int r,i,sum, ch,rem,ca = 0;

    while(scanf("%d %d",&r,&i) == 2 && (r != 0 || i != 0)){
        ca++;
         if(i == 0 || r == 0){
            printf("Case %d: impossible\n",ca);
        }
        else{
        sum = r - i;
        ch = sum / i;
        rem = sum % i;
        if(rem >= 1)
            ch++;

        if(ch > 26){
            printf("Case %d: impossible\n",ca);
        }
        else
            printf("Case %d: %d\n",ca,ch);
    }
    }
return 0;
}
