#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, j, test, t = 0;
    set <long long int> s;
    cin >> test;

    while(test--){
            t++;
        cin >> n;
        for(i = 2; i < n; i++){
            if(n % i == 0)
            s.insert(i);

            if(s.size() >= 2)
                break;
        }
    i = 1;
    printf("Case #%lld: %lld = ",t, n);
    set <long long int> :: iterator it;
    for(it = s.begin(); it != s.end(); it++){
        printf("%lld * %lld", *it, n / *it);
        if(i){
            printf(" = ");
            i = 0;
        }
        else
            printf("\n");
    }
    s.clear();
    }
}
