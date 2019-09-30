#include<stdio.h>
int main()
{
    char Count[20];
    int i,a,b,n;
    for(a=0;a<n;a++){
        scanf("%c",&Count[a]);
    }
    for(a=0;a<n;a++){
        for(b=a+1;b<n;b++){
            if(Count[a]<Count[b]){
                i=Count[a];
                Count[a]=Count[b];
                Count[b]=i;
            }
        }
    }
    for(a=0;a<n;a++){
        printf("%c",Count[a]);
    }
    return 0;
}
