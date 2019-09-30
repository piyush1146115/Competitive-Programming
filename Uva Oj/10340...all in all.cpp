#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    int a, flag, len1, len2, i, j;

    while(cin >>s1 >> s2){
        len1 = s1.size();
        len2 = s2.size();
        flag = 0;
        a = 0;
        //printf("%d %d",len1, len2 );
        for(i = 0; i < len1; i++){
            for(j = a; j < len2;j++){
                if(s1[i] == s2[j]){
                    a = j + 1;
                    break;
                }
            }
                    if(j == len2){
                    //printf("%d\n",j);
                    flag = 1;
                    break;
                    }

            }

        if(flag == 1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}
