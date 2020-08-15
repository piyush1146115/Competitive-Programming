#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    list<char> l;
    int i, j, k;

    while(cin >> s){
         list<char> :: iterator it;

         it = l.begin();

         for(i = 0; i < s.size(); i++){
            if(s[i] == '['){
                it = l.begin();
                continue;
            }
            else if(s[i] == ']'){
                it = l.end();
                continue;
            }
            else{
                l.insert(it, s[i]);
                //it++;
            }
         }

         for(it = l.begin(); it != l.end(); it++)
            printf("%c",*it);

         printf("\n");
         l.clear();
    }
    return 0;
}
