#include<stdio.h>
#include<math.h>
int main()
{
    int test, a, b, c, d, pr, dif;
    int y1, y2;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&d);
        pr = 0;
        for(a = 1; a <= d; a++){
            scanf("%d %d",&y1, &y2);

            b = y1 - y2;

            if(a == 1)
                c = b;
            else if(c != b){
                pr = 1;
            }
        }
        if(pr == 0){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        if(test)
        printf("\n");
    }
    return 0;
}
