#include<stdio.h>
int main()
{
    int ara[8],test, sum, a , b, c, temp;

    scanf("%d", &test);

    for(a = 1; a <= test; a++){
        sum = 0;
        for(b = 0; b < 7; b++){
            scanf("%d", &ara[b]);
            if(b < 4){
                sum = sum + ara[b];
            }
        }
        for(c = 4; c < 6; c++){
            if(ara[c] < ara[c + 1]){
                temp = ara[c+1];
                ara[c+1] = ara[c];
                ara[c] = temp;
            }
        }
        sum = sum + (ara[4] + ara[5])/2;
      if(sum >= 90) printf("Case %d: A\n",a);
      else if(sum >= 80) printf("Case %d: B\n",a);
      else if(sum >= 70) printf("Case %d: C\n",a);
      else if(sum >= 60) printf("Case %d: D\n",a);
      else printf("Case %d: F\n",a);
    }
    return 0;
}
