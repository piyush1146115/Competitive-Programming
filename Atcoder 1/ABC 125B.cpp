#include<bits/stdc++.h>
using namespace std;
#define MAX 25

int v[MAX], c[MAX];
int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        if(v[i] > c[i])
        sum += (v[i]-c[i]);
    }

    cout << sum << endl;
}
