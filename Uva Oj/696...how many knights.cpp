#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row, col, mul, a, b;



    while(scanf("%d %d", &row, &col) == 2){
            if(row == 0 && col == 0)
            break;

        int res;
        a = row;
        b = col;
        mul = row * col;

        if(row == 1 || col == 1)
            res = mul;
        else if(mul <= 4)
            res = mul;
        else if(row == 2 || col ==  2){
                int rem;

              row = max(row, col);

                rem = row % 4;

                if(rem == 0){
                    res = row / 2;
                }
                else if(rem == 1)
                    res = row / 2 + 1;
                else if(rem == 2 || rem == 3)
                res =( row - 2) / 2 + 2;
            res *= 2;
        }
        else{
            if(mul % 2 == 0)
                res = mul / 2;
            else
                res = mul / 2 + 1;
        }

        printf("%d knights may be placed on a %d row %d column board.\n", res, a, b);
    }
    return 0;
}
