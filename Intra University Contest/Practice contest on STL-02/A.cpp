#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> v(n +2);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.begin() + n);

    for(int i = 0; i < n - 1; i++)
        cout << v[i] << " ";

    cout << v[n-1] << endl;

}
