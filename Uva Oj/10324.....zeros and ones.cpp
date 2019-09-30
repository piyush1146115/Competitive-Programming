#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector <int> sum;
char str[1000005];
int main()
{
   // freopen("input.txt", "r", stdin);
    int i, j, k, len, s,cse = 0;

    while(gets(str)){

            cse++;
        len = strlen(str);
        if(len == 0)
            break;

        s = 0;
        for(i = 0; i < len; i++){
            s += str[i] - '0';
            sum.pb(s);
        }
        int qu, flag = 1;
        scanf("%d",&qu);

    while(qu--){
        int a, b, dif;
        scanf("%d %d",&a, &b);
        if(flag)
         printf("Case %d:\n",cse);

         flag = 0;

        if(a > b)
            swap(a,b);
        if(str[a] == '0'){
            dif = sum[b] - sum[a];
        if(dif == 0)
            printf("Yes\n");
        else
            printf("No\n");
        }
        else{
            dif = b - a;
            if(sum[b] - sum[a] == dif)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    getchar();
    sum.clear();
    }
    return 0;
}
