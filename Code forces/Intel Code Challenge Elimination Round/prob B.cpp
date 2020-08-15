#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    vector<int> v1, v2;
    int i, j, k, n;

    cin >> n;

    for(i = 0; i < n; i++){
        scanf("%d",&j);
        v1.push_back(j);
    }

    getchar();
    for(i = 0; i < n; i++){
        getline(cin, s);
        k = 0;
        for(j = 0; j < s.size(); j++){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y')
                k++;
        }
        v2.push_back(k);
    }

    if(v1 == v2)
        printf("YES\n");
    else
        printf("NO\n");

        return 0;
}

