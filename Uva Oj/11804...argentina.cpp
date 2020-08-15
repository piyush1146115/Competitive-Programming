#include<bits/stdc++.h>
using namespace std;
struct player{
string name;
int def, att;
}ara[15];

bool comp(player a, player b)
{
    if(a.att == b.att){
        if(a.def == b.def){
                return a.name < b.name;
        }
         else return a.def < b.def;
    }
    else return a.att > b.att;
}
int main()
{
   //freopen("input.txt", "r", stdin);
    int test, i, j, k, cse = 0;

    scanf("%d",&test);

    while(test--){
        for(i = 0; i < 10; i++){
           cin >> ara[i].name;
            scanf("%d %d",&ara[i].att, &ara[i].def);
        }
        cse++;
        sort(ara, ara+10, comp);

        for(i = 0; i < 4; i++){
            for(j = i + 1; j < 5; j++){
                if(ara[i].name > ara[j].name){
                    swap(ara[i], ara[j]);
                }
            }
        }

         for(i = 5; i < 9; i++){
            for(j = i + 1; j < 10; j++){
                if(ara[i].name > ara[j].name){
                    swap(ara[i], ara[j]);
                }
            }
        }
        printf("Case %d:\n",cse);
        cout << "(" << ara[0].name << ",";
        for(i = 1; i < 4; i++)
            cout << " "<< ara[i].name << ",";

        cout << " " << ara[4].name << ")" << endl;

        cout << "(" << ara[5].name << ",";
        for(i = 6; i <= 8; i++)
        cout << " "<< ara[i].name << ",";

        cout << " " << ara[9].name << ")" << endl;
    }
return 0;
}
