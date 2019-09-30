#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    unsigned long long ans, num , den;
    int test, mx, fq[30], i, j, k, cs = 0;

    vector<int>fc;
    string s;

    scanf("%d", &test);

    while(test--){
        cin >> s;

        memset(fq, 0,  sizeof(fq));

        mx = -1;

        for(i = 0; i < s.size(); i++){
            fq[s[i] - 65]++;
            mx = max(mx, fq[s[i] - 65]);
        }
        k = mx;
        for(i = 0; i < 30; i++){
                if(fq[i] == k){
                    k = -1;
                    continue;
                }
            if(fq[i] > 1)
                fc.push_back(fq[i]);
        }

        den = 1;
        for(i = 0; i < fc.size(); i++){
            for(j = 2; j <= fc[i]; j++){
                den *= j;
            }
        }

        num = 1;
        for(i = s.size(); i > mx;i-- )
            num *= i;

        ans = num/den;

        printf("Data set %d: %llu\n", ++cs, ans);
        fc.clear();
    }
    return 0;
}
