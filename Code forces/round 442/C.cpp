#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

int main()
{


    int n;

    cin >> n;
    cout << n + n/2 << endl;

    for(int i = 2 ; i <= n; i+= 2)
        cout << i << " ";

    for(int i = 1; i <= n; i+= 2)
        cout << i << " ";

    for(int i = 2; i <= n; i+= 2)
        cout << i << " ";

    cout << endl;

}
