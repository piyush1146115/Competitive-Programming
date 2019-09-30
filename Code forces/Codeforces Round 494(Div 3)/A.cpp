#include<bits/stdc++.h>
using namespace std;
int freq[105];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;

    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        freq[k]++;
        ans = max(ans, freq[k]);
    }

    printf("%d\n",ans);

}
