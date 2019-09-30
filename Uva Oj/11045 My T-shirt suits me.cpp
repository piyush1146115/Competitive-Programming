#include<bits/stdc++.h>
using namespace std;
int main()
{

   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    map <string , int> mp, av;
    pair<string, string>p[50];
    string s1, s2;
    int t, n, m, i, j, div;

    scanf("%d", &t);

    while(t--){
            int flag = 1;
        scanf("%d %d", &n, &m);
        div = n / 6;
        av["XXL"] = av["XL"] = av["L"] = av["M"] = av["S"] = av["XS"] = div;
       // cout << av["XXL"] << endl;
        for(i = 0; i < m; i++){
            cin >> s1 >> s2;
            mp[s1]++;
            mp[s2]++;
            p[i] = make_pair(s1, s2);
        }

        for(i = 0;i < m; i++){
               if(av[p[i].first] > 0 || av[p[i].second] > 0){
                if(av[p[i].first] > 0)
                    av[p[i].first]--;
                else
                    av[p[i].second]--;
               }
               else
                flag = 0;

        }
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
/*
    map<string,int> :: iterator  it;
    for(it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }*/
    mp.clear();
    av.clear();
    }
return 0;
}
