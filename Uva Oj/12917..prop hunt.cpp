#include<stdio.h>
int main()
{
    int p, q, r;

    while(scanf("%d %d %d",&p, &q, &r) == 3){
        if(r - p >= q){
            printf("Props win!\n");
        }
        else
            printf("Hunters win!\n");
    }
    return 0;
}
