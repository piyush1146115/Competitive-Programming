#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, inc, i, j, k, m, n,rem;
    vector <int> v;

    while(scanf("%d", &n) == 1 && n  != 0)
    {
        m = n;
        rem = 1;
        inc = 0;
        while(rem != 13){
        inc++;
        m = n;
        a = 1;
        for(i = 1; i <= n;i++){
            v.push_back(i);
        }

        while(v.size() > 1){

            if(a > m && a % m == 0)
                a = m;
            else if(a != m)
                a = a % m;

        v.erase(v.begin() + (a - 1));

        m--;
        a += inc;
        a--;
        }
        rem = v[0];
        v.clear();
    }
    cout << inc << endl;
    }
    return 0;
}
