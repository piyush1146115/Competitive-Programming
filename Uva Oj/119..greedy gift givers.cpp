#include<bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "wt", stdout);

    map<string, int> m;
    string s1[150], a, b;
    int n, i, rem, add, sub, div, j, k = 0;

    while(scanf("%d", &n) == 1){

        for(i = 0; i < n; i++){
            cin >> s1[i];
            //m[s1[i]] = 0;
        }

        for(i = 0; i < n; i++){
            cin >> a;
            cin >> sub >> div;
          if(div != 0){
            add = sub / div;
            sub = add * div;
            m[a] -= sub;
            for(j = 0; j < div; j++){
                cin >> b;
                m[b] += add;
            }
          }
        }
        if(k != 0)
            printf("\n");
        for(i = 0; i < n; i++)
            cout << s1[i] << " " << m[s1[i]] << "\n";
            k++;
            m.clear();
    }
    return 0;
}
