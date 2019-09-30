#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin);
    int test, x;
    char a[4];

    cin >> test;
    //getchar();
    x = 0;
    while(test--){
        scanf("%s",a);
        if(a[0] == '+' || a[1] == '+' || a[2] == '+'){
            x++;
        }
        else{
            x--;
        }
    }
    cout << x << endl;

    return 0;
}
