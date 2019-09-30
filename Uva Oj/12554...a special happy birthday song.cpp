#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[16][10] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia",
                           "Happy", "birthday", "to", "you"};
    char name[102][102];

    int i, j, k, n, a, b;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", name[i]);
    }

    a = n / 16;
    b = n % 16;

    if(b != 0){
        a += 1;
    }

    k = 0;

    for(i = 1; i <= a; i++){
        for(j = 0; j < 16; j++){
            printf("%s: %s\n",name[k], str[j]);
            k++;
            if(k == n){
                k = 0;
            }
        }
    }
    return 0;
}
