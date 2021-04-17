#include<bits/stdc++.h>
using namespace std;

int color[55];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q;

    cin >> n >> q;


    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        if(color[k] == 0){
            color[k] = i;
        }
    }

    while(q--){
        int k;
        cin >> k;

        cout << color[k] << " ";

        for(int i = 1; i <= 50; i++){
            if(color[i] < color[k])
                color[i]++;
        }
        color[k] = 1;
    }
    cout << endl;

}
