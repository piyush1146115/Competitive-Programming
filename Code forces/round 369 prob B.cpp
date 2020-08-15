#include<bits/stdc++.h>
using namespace std;
#define mx 505
long long int ara[mx][mx];
int main()
{
    set<long long int> s;
    long long int n,  i, j, k, l, sum ;

    scanf("%I64d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            scanf("%I64d", &ara[i][j]);
        }

    for(i = 0; i < n; i++){
            sum = 0;
        for(j = 0; j < n; j++){
            sum += ara[i][j];
        }
    s.insert(sum);
    }


    for(i = 0; i < n; i++){
            sum = 0;
        for(j = 0; j < n; j++){
            sum += ara[j][i];
        }
    s.insert(sum);
    }
    sum = 0;
    for(i = 0; i < n; i++){
        sum += ara[i][i];
    }
    s.insert(sum);
    sum = 0;
    for(i = 0; i < n; i++){
        sum += ara[i][n - i - 1];
    }
    s.insert(sum);

    if(s.size() > 2){
        printf("-1\n");
    }
    else if(n == 1){
        printf("1\n");
    }
    else if(s.size() ==1){
        printf("-1\n");
    }
    else{
        set<long long int> :: iterator it, itt;
        it = s.begin();
        itt = s.begin();
        itt++;
        long long int res = abs(*it - *itt);
        printf("%I64d\n",res);
    }
    return 0;
}
