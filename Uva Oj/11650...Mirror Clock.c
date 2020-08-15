#include<stdio.h>
int main()
{
    int a,b,c, i, j, k, h1, m1, h2, m2, test;
    char ch;
    scanf("%d",&test);

    for(a = 1; a <= test; a++){
        scanf("%d : %d",&h1,&m1);

        b = h1 * 60;
        c = b + m1;
        i= 720 - c;
         h2 = i /60;
         m2 = i % 60;

         if(h2 == 0){
            h2 += 12;
         }
         if(m2 < 0){
            h2 -= 1;
            m2 = 60 + m2;
         }
            printf("%02d:%02d\n",h2,m2);

      }
    return 0;
}
