#include<bits/stdc++.h>
using namespace std;
int freq[11];
int main()
{
    int n, k, mx = -1,  i, j ,a , b, num, cost = 0, c, dif;
    char str[10005];

    cin >> n >> k;
    cin >> str;

    for(i = 0; i < n; i++){
        freq[str[i] - '0']++;
        if(freq[str[i] - '0'] > mx){
            mx = freq[str[i] - '0'];
            num = str[i];
        }
    }
    k -= mx;
    vector <int> v;
    for(i = 1; i < 10; i++){
            c = 0;
            if(k > 0){
        for(j = 0; j < n; j++){
            dif = abs(str[j] - num);
            if(dif == i){
                v.push_back(str[j]);
                c++;
            }
        }
        if(c > k){
            sort(v.begin(), v.end());
            for(a = v.size() - 1; a >= 0; a--){
                    if(k <= 0)
                    break;
                for(b = 0; b < n; b++){
                    if(str[b] == v[a]){
                        str[b] = num;
                        k--;
                        cost += i;
                        break;
                    }
                }
            }
        }
        else{
            for(a = 0; a < n; a++){
                    if(k <= 0)
                    break;
            dif = abs(str[a] - num);
            if(dif == i){
                str[a] = num;
                k--;
                cost += i;
            }
            }
        }
        v.clear();
            }
    }
    cout << cost << endl << str << endl;

}
