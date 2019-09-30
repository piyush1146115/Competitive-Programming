#include<stdio.h>
int main()
{
    int test, m, n, x, y;

    while(scanf("%d", &test) == 1 && test != 0){
        scanf("%d %d",&n, &m);

        while(test--){
            scanf("%d %d", &x, &y);
            if(x == n || y == m){
                printf("divisa\n");
            }
            else if(x < n && y > m){
                printf("NO\n");
            }
            else if(x > n && y > m){
                printf("NE\n");
            }
            else if(x > n && y < m){
                printf("SE\n");
            }
            else if(x < n && y < m){
                printf("SO\n");
            }
        }
    }
    return 0;
}
