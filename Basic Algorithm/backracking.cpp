#include<bits/stdc++.h>
using namespace std;
int ara[] = {1, 2, 3, 4};
int n = 4, taken[6], val[6];

void gen(int idx)
{
    int i, j;

    if(idx == n){
        for(i = 0; i < n; i++)
            printf("%d ",val[i]);

        printf("\n");

        return;
    }

    for(i = 0; i < n; i++){

        if(taken[i] == 0){
            taken[i] = 1;
            val[idx] = ara[i];
            gen(idx + 1);
            taken[i] = 0;
        }
    }

}
int main()
{
    gen(0);
}
