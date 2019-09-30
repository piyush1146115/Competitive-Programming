#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    string s;
    int i, j, k, n, co = 0;

    cin >> n >> s;

    for(i = 0; i < n; i++){
            co = 0;
        while(s[i] == 'B'){
            i++;
            co++;
            if(i == n)
                break;
        }
        if(co != 0)
            v.push_back(co);
    }

    if(v.size() == 0)
        printf("0\n");

    else{
        printf("%d\n",v.size());
        for(i = 0; i < v.size(); i++)
            printf("%d ",v[i]);

        printf("\n");
    }
    return 0;
}
