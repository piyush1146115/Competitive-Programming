#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

int main()
{
    vector<string> vs;

    string s;
    cin >> s;

    for(int i = 0; i <  (int)s.size() ; i++){
    string temp = "";
    for(int j = i; j <  (int)s.size() ; j++){
        temp += s[j];
        vs.pb(temp);
    }
    }
    int cnt = 0;

    for(int i = 0; i < (int)vs.size(); i++){
        if(vs[i] == "Danil")cnt++;
        if(vs[i] == "Olya")cnt++;
        if(vs[i] == "Slava")cnt++;
        if(vs[i] == "Ann")cnt++;
        if(vs[i] == "Nikita")cnt++;
    }

    if(cnt == 1)
        printf("YES\n");
    else
        printf("NO\n");

}

