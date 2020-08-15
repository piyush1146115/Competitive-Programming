#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    int l1 = s1.size() - 1;
    int l2 = s2.size() - 1;
    int cnt = 0;
    while(l1 >= 0 && l2 >= 0){
        if(s1[l1] == s2[l2]){
            l1--;
            l2--;
            cnt++;
        }
        else{
            break;
        }
    }
    int ans = (s1.size() - cnt) + (s2.size() - cnt);

    printf("%d\n",ans);

}
