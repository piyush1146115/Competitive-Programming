#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, pet, vas;

    cin >> n >> m;

    pet = max(n, m) - 1;
    vas = min(n, m);

    printf("%d %d\n",pet, vas);

    return 0;
}
