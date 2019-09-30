#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> div;
    int m, n, i, j;

    cin >> n;
        div.push_back(n);
    while(n > 1){
        m = n / 2;
        while(n % m != 0 && m > 1)
            m--;
        div.push_back(m);
        n = m;
        continue;
    }
    for(i = 0; i < div.size(); i++)
        printf("%d ",div[i]);

    printf("\n");
}
