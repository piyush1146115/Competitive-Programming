#include<bits/stdc++.h>
using namespace std;
int main()
{

    int test;

    scanf("%d", &test);

    while(test--){
        int n;
        scanf("%d", &n);

        string s;
        cin >> s;
        int x = 0, o = 0;

        for(int i = 0; i < n; i++){
         if(s[i] == 'X'){
            x++;
            while(i  < n && s[i] == 'X'){
                i++;
            }
            i--;
         }
         else{
            o++;
            while(i  < n && s[i] == 'O'){
                i++;
            }
            i--;
         }
        }

        if(x >= o){
            printf("X\n");
        }
        else{
            printf("O\n");
        }
    }
}
