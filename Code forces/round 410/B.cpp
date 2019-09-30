#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx
#define pb push_back
#define mkp make_pair

int fun(string a, string b)
{
    if(a.size() != b.size())
        return -1;
//cout << a <<" "  << b << endl;

    for(int i = 0; i < b.size(); i++){
        if(b[i] == a[0]){
                int k = i, j;
                //cout << k << endl;
            for( j = 0; j < a.size(); j++){
                if(a[j] == b[k]){
                    k++;
                    if(k == b.size())
                        k = 0;
                }
                else
                    break;
            }
            if(j == a.size()){
                return i;
                //cout << a << " " << b << " " << i << endl;
            }
        }
    }
    return -1;
}
int main()
{
    string s[55];

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int ans = 0, res = 1200000;
    for(int i = 0; i < n; i++){
            ans = 0;
        for(int j = 0; j < n; j++){
            int ret = fun(s[i], s[j]);
            if(ret == -1){
                printf("-1\n");
                return 0;
            }
            ans += ret;
        }
    res = min(ans, res);
    }

    printf("%d\n",res);
}

