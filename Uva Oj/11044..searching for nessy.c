#include<stdio.h>
int main()
{

    long long int m, n, s, d, e, i, j,r_rem, c_rem,row,col, a, test, grid;

    scanf("%lld",&test);

    for(a = 1; a <= test; a++){
    scanf("%lld %lld",&m, &n);

    row = m - 2;
    col = n - 2;

    r_rem = row % 3;
    c_rem = col % 3;

    i = row - r_rem;
    j = col - c_rem;

    grid = i * j;
    s = grid / 9;

    if(r_rem > 0){
        d = col/3;
        if(c_rem > 0){
            s = s + d + 1;
        }
        else{
            s = s + d;
        }
    }
    if(c_rem > 0){
        row = row - 2;
        d = row / 3;
        e = row % 3;
        if(e > 0){
            s = s + d + 1;
        }
        else{
            s = s + d;
        }
    }

    printf("%lld\n",s);
}
return 0;
}
