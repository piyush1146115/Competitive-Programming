#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[200];
    int i, j, k, len, test, flag;
    stack<char>st;
    scanf("%d", &test);
    getchar();

    while(test--){
        flag = 1;
    // scanf("%s",s);
        gets(s);
        len = strlen(s);

        for(i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
               }
               else{
                     if(st.empty()){
                        flag = 0;
                        break;
                    }
                if(s[i] == ')'){
                    if(st.top() != '(')
                    {
                        flag = 0;
                        break;
                    }
                    st.pop();
                }
                else if(s[i] == ']'){
                    if(st.top() != '[')
                    {
                        flag = 0;
                        break;
                    }
                    st.pop();
                }
               }
        }
         while(!st.empty()){
            flag = 0;
            st.pop();
        }
        if(flag){
            printf("Yes\n");
        }
        else
            printf("No\n");


    }
   return 0;
}
