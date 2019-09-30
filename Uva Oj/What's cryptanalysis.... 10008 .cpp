#include<bits/stdc++.h>
using namespace std;

struct analysis{
char c;
int value;
};
char str[1000][1000];
struct analysis ara[30], temp;

bool comp(analysis a, analysis b)
{
    if(a.value != b.value)
        return a.value > b.value;

    else
        return a.c < b.c;
}

int main()
{
    int a, len, n, i, j;


    scanf("%d", &n);
    getchar();

    for(i = 0; i < 30; i++)
        ara[i].value= 0;

    for(i = 0; i < n; i++){
        gets(str[i]);

    }

    for(i = 0; i < n; i++){
        len = strlen(str[i]);
        for(j = 0; j < len; j++){
            if(str[i][j] >= 'a' && str[i][j] <= 'z'){
                a = str[i][j] - 'a';
                ara[a].c = a + 65;
                ara[a].value++;
            }

           else if(str[i][j] >= 'A' && str[i][j] <= 'Z'){
                a = str[i][j] - 'A';
                ara[a].c = a + 65;
                ara[a].value++;
            }
        }
        }


   /* for(i = 0; i < 25; i++){
        for(j = i + 1; j < 26; j++){
            if(ara[i].value < ara[j].value){
                temp = ara[i];
                ara[i] = ara[j];
                ara[j] = temp;
            }
        }
    }
*/

    sort(ara, ara + 26, comp);

    for(i = 0; i < 26; i++){
        if(ara[i].value > 0){
            printf("%c %d\n",ara[i].c, ara[i].value);
        }
    }
    return 0;
}
