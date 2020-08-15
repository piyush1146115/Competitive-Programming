#include<stdio.h>
int main()
{
    int h1, m1, h2, m2, result, i, j, k;

    while(scanf("%d %d %d %d",&h1, &m1, &h2, &m2) == 4 &&(h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0)){
        if(h1 > h2){
            h2 += 24;
        }
        i = h2 - h1;
        j = m2 - m1;
        if(i == 0 && j < 0){
            i = 24;
        }
        result = (i * 60) + j;

        printf("%d\n",result);
    }
    return 0;
}
