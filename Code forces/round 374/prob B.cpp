#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i, j, best = 0 , worst = 0, co, corr;
    string s;
    vector<int> v;

    cin >> n >> k;

    for(i = 0; i < n; i++){
        cin >> s;
        v.push_back(s.size());
    }

    cin >> s;

    corr = s.size();

    sort(v.begin(), v.end());

    co = 0;
    for(i = 0; i < v.size(); i++){
        if(v[i] < corr)
            co++;

        if(v[i] == corr)
        {
            break;
        }
    }

    best = co + ((co/ k) * 5);
    best++;


    while(i < v.size() && v[i] == corr){
        co++;
        i++;
    }
    co--;
    worst = co + ((co/ k) * 5);

    worst++;
    cout << best << " " << worst << endl;

    return 0;
}
