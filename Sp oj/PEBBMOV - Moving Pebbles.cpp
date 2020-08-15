#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n, k;
    while(cin >> n){
  //  scanf("%llu", &n);
        string s;
        set<string> Set;

    for(int i = 0; i < n; i++)
    {
        //scanf("%llu", &k);
        cin >> s;
     set<string> :: iterator it;
     it = Set.find(s);
     if(it == Set.end())
            Set.insert(s);
     else
        Set.erase(it);
    }

    if(!Set.empty())
     cout << "first player\n";
    else
        cout << "second player\n";

    }
}

