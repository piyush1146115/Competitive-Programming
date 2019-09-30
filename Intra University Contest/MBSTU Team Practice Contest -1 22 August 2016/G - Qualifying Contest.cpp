#include<bits/stdc++.h>
using namespace std;
#define ss second
#define ff first

vector<pair<string, int> > v[10005];
bool comp(pair<string, int>a , pair<string, int> b)
{
    return  a.ss > b.ss;
}
int  main()
{
    int i, j, g, n, gr, marks;
    string s;

    scanf("%d %d", &n, &g);

    for(i = 0; i < n; i++){
        cin >> s>> gr >> marks;
        v[gr].push_back(make_pair(s, marks));
    }

    for(i = 1; i <= g; i++){
        sort(v[i].begin(), v[i].end(), comp);

        if(v[i].size() > 2 && v[i][1].ss == v[i][2].ss){
            printf("?\n");
        }
        else{
                cout << v[i][0].ff << " " << v[i][1].ff << endl;
        }
    }
    return 0;
}
