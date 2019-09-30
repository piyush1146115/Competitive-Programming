#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("input.txt", "r", stdin);

    map <string, int> m;
    string co[2010], wo[2010];
    int test, i, j, k;

    while(cin >> test){

    for(i = 0; i < test; i++){
        cin >> co[i];
        getline(cin, wo[i]);
        m[co[i]]++;
        for(j = i; j > 0; j--){
            if(co[j] < co[j - 1])
                swap(co[j], co[j -1]);
            else
                break;
        }
    }
    for(i = 0; i < test; i++){
        j = i;
        cout << co[i] << " " << m[co[i]] << endl;
        i += (m[co[j]] - 1);
    }
    m.clear();
    }
    return 0;
}
