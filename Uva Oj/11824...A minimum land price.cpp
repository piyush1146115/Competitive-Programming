#include<bits/stdc++.h>
using namespace std;

long long power(long long int b,long long int p)
{
    long long ans = 1;

    while(p){

    if(p & 1){
            ans *= b;
        }
        b *= b;
     p = p / 2;
    }
    return ans;
}

int main()
{
    vector <long long> vec;
    long long int i, j, n, test, sum, flag, k;

    scanf("%lld",&test);

    for(i = 1; i <= test; i++){

        while(scanf("%lld",&n) == 1 && n != 0){
            vec.push_back(n);
        }
        sum = 0;
        flag = 0;
        sort(vec.begin(), vec.end());
        k = 0;
        for(j = vec.size() - 1; j >= 0; j--){
            sum += (2 * power(vec[j], ++k));

            //printf(" s : %lld\n",sum);
            if(sum > 5000000){
                    flag = 1;
                break;
            }
        }
        if(flag){
            printf("Too expensive\n");
        }
        else{
            printf("%lld\n", sum);
        }
        vec.clear();
    }
    return 0;
}
