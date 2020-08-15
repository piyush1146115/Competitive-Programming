#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack <char> st;
    int cnt = 0, i, j;
    string s;

    cin >> s;

    for(i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
           }
           else if(s[i] == ')'){
            if(!st.empty()){
                if(st.top() == '('){
                    cnt++;
                    st.pop();
                   }
            }
           }
    }
    printf("%d\n",cnt * 2);

    return 0;
}
