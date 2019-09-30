#include<bits/stdc++.h>
using namespace std;
vector <int> prime;
int ara[10055];
long long int euler[10005];
int c[10005];
void sieve()
{
    int i, j, k;
    prime.push_back(2);

    for(i = 3; i <= 108; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 10050; j += (i + i)){
                ara[j] = 1;
            }
        }
    }

    for(i = 3; i <= 10050; i += 2)
        if(ara[i] == 0)
            prime.push_back(i);
}
void eu()
{
    long long int i, n;

    for(i = 0; i <= 10001; i++){
        n = (i*i)+ i+ 41;
        euler[i] = n;
    }
}

void cont()
{
    int i, k = 0, sqr, j, flag;

    for(i = 0; i <= 10001; i++){

                flag = 1;
            sqr = sqrt(euler[i]);

            for(j = 0; prime[j] <= sqr; j++){
                if(euler[i] % prime[j] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                k++;

            c[i] = k;
        }


}
int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt","wt", stdout);
    sieve();
    eu();
    cont();

    int n, a, b;
    double div, per, dif, dis;

    while(scanf("%d %d",&a, &b) == 2){
        dis = double((b - a) + 1);
        if(a > 0){
            if(c[a] == c[a - 1])
                dif = (double)(c[b] - c[a]);
            else
                dif = (double)(c[b] - c[a] + 1);
        }
        else
            dif = (double)(c[b] - c[a] + 1);

        div = (dif/ dis);
        per = div * 100.0;
        per += 1e-9;
        printf("%0.2lf\n",per);
    }
return 0;
}
