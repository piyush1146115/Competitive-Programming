#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    scanf("%d", &n);

    string s1 = "aabb";
    string s2 = "aabb";

    int flag1 = 1, flag2 = 0;

    int cnt = 0;
    int i = 0;
    while(cnt < n){

        if(flag1)
        printf("%c",s1[i]);
        else
            printf("%c",s2[i]);

        i++;
        cnt++;

        if(flag1){
            if(i == s1.size()){
                flag1 = 0;
                flag2 = 1;
                i = 0;
            }
        }
        if(flag2){
            if(i == s2.size()){
                flag1 = 1;
                flag2 = 0;
                i = 0;
            }
        }
    }
    printf("\n");
}
