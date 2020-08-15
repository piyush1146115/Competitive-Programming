#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, i, j, k, flag;
    string s, sb;

    scanf("%d", &test);

    while(test--){
        cin >> s;
        scanf("%d", &k);

        while(k--){
            cin >>sb;
            flag = 1;

            for(i = 0; i < sb.size(); i++){
                if(i < s.size()){
                    if(s[i] != sb[i]){
                        flag = 0;
                    }
                }
                else{
                    flag = 0;
                }
            }
            if(flag)
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
