#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j , k, c = 0, d = 0;
    string s;

    cin >> n >> s;

    for(i = 0; i < n; i++){
            int flag = 1;
        if(s[i] == '('){
            while(i < n && s[i] != ')'){
            if(flag){
            if(isalpha(s[i])){
            c++;
            flag = 0;
           }
           }
           if(s[i] == '_')
            flag = 1;

           i++;
           }
           }

           k = 0;
           while(i < n && isalpha(s[i])){
            i++;
            k++;
           }

           if(k)
            i--;

           d = max(d, k);

    }

    printf("%d %d\n",d, c);

}
