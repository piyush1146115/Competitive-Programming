#include<bits/stdc++.h>
using namespace std;
int ara[1000005];

void self()
{
    int i, j, k, num, sum = 0;

    for(i = 1; i <= 1000000; i++){
            j = i;
            k = 0;
            while(j != 0){
                k = k + (j % 10);
                j = j / 10;
            }
            sum = i + k;
            ara[sum] = 1;
    }
}
int main()
{
self();
int i;
for(i = 1; i <= 1000000; i++)
    if(ara[i] == 0)
    printf("%d\n",i);

return 0;
}
