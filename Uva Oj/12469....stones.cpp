#include<bits/stdc++.h>
using namespace std;

int stone(int n)
{
    int i, j, k;

    if(n <= 1)
        return 0;

    i = n / 2;

    loop:
    j = n - i;

    if(j <= 2 * i){
        i--;
    if(i >= 1)
    goto loop;
    }

    return j;
}


int main()
{
    int n , j, k, count ;

    while(scanf("%d", &n) == 1 && n != 0){
        k = stone(n);
        count = 1;
        while(k != 0)
        {
            if(k - 1 <= 2){
                count++;
                break;
            }
            count++;
            k = stone(k);

        }

        if(count % 2 != 0){
            printf("Robert\n");
        }
        else{
            printf("Alice\n");
        }
    }
return 0;
}
