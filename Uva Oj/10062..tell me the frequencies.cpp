#include<bits/stdc++.h>
using namespace std;

struct freq{
int value;
int cont;
} ;

struct freq ara[505];
bool comp(freq a, freq b)
{
    if(a.cont != b. cont)
    return a.cont < b.cont;
    else
        return a.value > b.value;
}
int main()
{
    int len, i, j, k, c = 0;
    char str[1500];

    for(c = 0; ; c++){
        for(i = 0; i < 500; i++)
            ara[i].cont = 0;

      if (!gets(str)) break;
        if (c > 0) printf("\n");

        len = strlen(str);

        for(i = 0; i < len; i++){
            ara[str[i]].value = str[i];
            ara[str[i]].cont++;
        }
        sort(ara, ara + 500, comp);

        for(i = 0; i < 500; i++){
            if(ara[i].cont > 0){
                printf("%d %d\n",ara[i].value, ara[i].cont);
            }
        }
    }

    return 0;
}
