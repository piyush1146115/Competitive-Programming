#include<stdio.h>
int main()
{
    int y, m, d, y1, y2, m1, m2, d1, d2, a, b, c, test;

    scanf("%d",&test);

    for(a = 1; a <= test; a++){
        //getchar();
        //printf("\n");
        scanf("%d/%d/%d",&d1, &m1, &y1);
        scanf("%d/%d/%d",&d2, &m2, &y2);

        y = y1 - y2;
        d = d1 - d2;
        m = m1 - m2;

          if(y > 0){
            if(m < 0){
                y--;
            }
            else if(m == 0){
                if(d < 0){
                    y--;
                }
            }
             if(y > 130){
            printf("Case #%d: Check birth date\n",a);
        }

            else
                printf("Case #%d: %d\n",a, y);
        }


        else{
            if(y < 0){
                printf("Case #%d: Invalid birth date\n",a);
            }
            else{
                if(m < 0){
                    printf("Case #%d: Invalid birth date\n",a);
                }
                else if(m == 0){
                    if(d >= 0){
                        printf("Case #%d: 0\n",a);
                    }
                    else
                        printf("Case #%d: Invalid birth date\n",a);
                }
                else
                    printf("Case #%d: 0\n",a);
            }
        }
    }

    return 0;
}
