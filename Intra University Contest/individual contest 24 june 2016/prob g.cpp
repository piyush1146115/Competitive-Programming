#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, test, s, sum = 0, n, ara[105], p, k = 0;

    cin >> test >> s;
    for(i = 0; i < test; i++){
        scanf("%d",&n);
        if(n < 0){
        ara[k++] = n * -1;
        }
        }
        sort(ara, ara + k);

    int c = 0;
     for(i = k - 1; i >= 0; i--){
            c++;
        sum += ara[i];
     if(c == s)
        break;
     }

    cout << sum << endl;
}
