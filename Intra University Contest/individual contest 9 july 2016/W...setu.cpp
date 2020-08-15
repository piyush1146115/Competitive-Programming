#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, i, j, op, cs = 0, sum = 0;
    string s;

    scanf("%d",&test);

    while(test--){
            sum = 0;
            scanf("%d", &op);
        printf("Case %d:\n",++cs);
        while(op--){
            cin >>  s;
            if(s == "report"){
                printf("%d\n", sum);
            }
            else{
                cin >> j;
                sum += j;
            }
        }
    }
    return 0;
}
