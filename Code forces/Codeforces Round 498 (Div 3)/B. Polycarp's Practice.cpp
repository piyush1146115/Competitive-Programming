#include<bits/stdc++.h>
using namespace std;
vector<int>v, vc, vk;
int main()
{
    int n, k;
    scanf("%d %d",&n, &k);

    for(int i = 0; i < n; i++)
    {
        int q;
        scanf("%d", &q);
        v.push_back(q);
    }
    vc = v ;
    sort(v.begin(),v.end());
    reverse(v.begin(), v.end());
///4 2
///1 2000 2000 2

    int cnt = 0, ans = 0, tot = 0;
    for(int i = 0; i < k; i++){
        ans += v[i];
    }


    for(int i = 0; i < n; i++){
        cnt++;
        for(int j = 0; j < k; j++){
            if(vc[i] == v[j]){
                v[j] = -1;
                if(vk.size() != k -1){
                vk.push_back(cnt);
                cnt = 0;
                }
                break;
            }
        }
    }

    if(cnt > 0)
    vk.push_back(cnt);

    printf("%d\n",ans);
    for(int i = 0; i < k; i++){
        printf("%d  ", vk[i]);
    }

    return 0;
}
