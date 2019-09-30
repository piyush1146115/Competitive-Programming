#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r, c, mul, test, res;
    string s;

    scanf("%d", &test);

    while(test--){
        cin >> s >> r >> c;
        if(s == "k"){
            mul = r * c;
            res = (mul / 2) + (mul % 2);
        }
        else if(s == "K"){
            res = ((r / 2) + (r % 2)) * ((c / 2) + (c % 2));
        }
        else{
            res = min(r, c);
        }
        printf("%d\n",res);
    }
    return 0;
}
