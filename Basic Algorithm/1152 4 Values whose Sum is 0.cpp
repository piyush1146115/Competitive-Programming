#include<bits/stdc++.h>
using namespace std;
#define mxx 4005

int a[mxx], b[mxx], c[mxx], d[mxx];

int main()
{
    int n, m, test;

    cin >> test;

    while(test--){
        scanf("%d",&n);

        for(int i= 0; i < n; i++){
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        }

        vector<long long int> v1, v2;

        for(int i = 0 ;i < n;i++){
            for(int j = 0; j < n;j++){
                v1.push_back(a[i] + b[j]);
            }
        }
        for(int i = 0 ;i < n;i++){
            for(int j = 0; j < n;j++){
                v2.push_back(c[i] + d[j]);
            }
        }

      //  vector<long long int> :: iterator lo, up;

        sort(v2.begin(), v2.end());
        int ans = 0;

        for(int i = 0 ; i < v1.size(); i++){
                int x = v1[i];

        int lo = lower_bound(v2.begin(), v2.end(), (-x)) - v2.begin();
        int up = upper_bound(v2.begin(), v2.end(), (-x)) - v2.begin();

        ans += (up - lo );
        }
        printf("%d\n", ans);

        if(test)
            printf("\n");

    }
    return 0;
}
