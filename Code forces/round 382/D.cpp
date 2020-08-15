#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, j;

    cin >> n;

    int prime = 1;

    for(i = 2; i*i <= n; i++ ){
        if(n% i == 0){
            prime = 0;
            break;
        }
    }

    int prime2 = 0;

    if(n % 2 == 1){
    int m = n - 2;
    //cout << m << endl;

    for(i = 2; i*i <= m; i++ ){
        if(m % i == 0){
            prime2 = 1;
            break;
        }
    }
    }

    if(prime){
        printf("1\n");
    }
    else if(n % 2 == 0){
        printf("2\n");
    }
    else if(n % 2 == 1 && prime2 == 0){
        printf("2\n");
    }
    else{
        printf("3\n");
    }
    return 0;
}
