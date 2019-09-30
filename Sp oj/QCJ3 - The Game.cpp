#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        int n;
        scanf("%d", &n);

        vector<int> v;

        for(int i =  1; i <= n; i++){
            int k;
            scanf("%d", &k);
            if(k  % 2 == 1){
                v.push_back(i);
            }
        }

        int ans = 0;

        for(int i = 0; i < (int)v.size(); i++)
            ans ^= v[i];

        if(ans > 0){
            printf("Tom Wins\n");
        }
        else{
            printf("Hanks Wins\n");
        }
    }
}
