#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<long long, long long> m;
    vector<long long> v;
    long long  i, j, k, n1, n2, num, dif;

    while(scanf("%lld", &num) == 1 , num){
        dif = 0;
        k = 0;
        printf("Original number was %lld\n", num);
        while(m[dif] <= 1){
                    if(num == 0)
                v.push_back(0);
            k++;
            while(num != 0){
                v.push_back(num % 10);
                num /= 10;
            }
            sort(v.begin(), v.end());
            n1 = n2 = 0;
            for(i = v.size() -1; i >= 0; i--){
                n1 = v[i] + n1* 10;
            }
            for(i = 0; i < v.size(); i++){
                n2 = v[i] + n2 * 10;
            }
            dif = n1 - n2;

            printf("%lld - %lld = %lld\n", n1, n2, dif);
            m[dif]++;
            num = dif;
            v.clear();
        }
        printf("Chain length %lld\n\n",k);

        m.clear();
    }
}
