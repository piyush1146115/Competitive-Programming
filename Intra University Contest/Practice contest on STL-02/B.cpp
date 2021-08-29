#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> v;
    int l, r;

    for(int i = 0; i < n; i++)
    {
        cin >> l;
        v.push_back(l);
    }


    cin >> l;
    l--;
    v.erase(v.begin() + l);
    cin >> l >> r;
    l--;
    r--;

    r = min(r, (int)v.size() -1);

    v.erase(v.begin() + l, v.begin() + r);


    cout << v.size() << endl;

    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " ";

    if(v.size() > 0)
        cout << v[v.size() - 1] << endl;

    v.clear();

}
