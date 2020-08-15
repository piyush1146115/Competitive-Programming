#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, x, y, i, k, sq;

    cin >> n >> x >> y;

    sq = y - (n - 1);

    if(sq < 1){
        printf("-1\n");
    }
   else if((sq* sq + ( 1 * (n - 1))) < x){
        printf("-1\n");
    }
    else{
        cout << sq << endl;
        for(i = 1; i < n; i++)
            printf("1\n");
    }
    return 0;
}
