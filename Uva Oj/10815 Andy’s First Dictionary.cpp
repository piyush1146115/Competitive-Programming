#include<bits/stdc++.h>
using namespace std;
int main()
{
  //  freopen("input.txt", "r", stdin);

    set <string> res;
    string s, in;
    int i, j, l;

    while(cin >> s){
/*
        for(i = 0; i < in.size(); i++){
            if(isalpha(in[i])){
                s.push_back(tolower(in[i]));
            }
            else if(s != " "){
                ans.insert(s);
                s.clear();
            }
        }*/
        string p="";
        int l=s.size();
        for(int i=0;i<=l;i++){
           if(isalpha(s[i])){
            p+=tolower(s[i]);
           }
           else if(p!=""){
           res.insert(p);
           p="";
           }
    }
    }
    set <string> :: iterator it;

    for(it = res.begin(); it != res.end(); it++)
        cout << *it << endl;

    res.clear();

    return 0;
}
