/*#include<bits/stdc++.h>
using namespace std;
int ara[100005],flag[100005];
int main()
{
     long long sum, s1, s2;
    int td, ta, h, n, test, cse = 0;
    int  i, j, k;
    scanf("%d", &test);

    while(test--){
            cse++;
            s1 = s2 = 0;
        scanf("%d %d %d %d",&n, &h, &ta, &td);

            for(i = 0; i < n; i++){
                scanf("%d", &ara[i]);
                flag[i] = 0;
            }
            s1 = ta * n;
            j = n % 2;
            s2 = (td * (n / 2)) + (j * ta);
            if(s1 <= s2){
                printf("Case %d: %lld\n",cse, s1);
            }
            else{
            sort(ara, ara + n);
            int c = 0, p = n  - 1;
               for(i = 0; i < n - 1; i++){
                    if(flag[i] == 1)
                    continue;

               while(p > i && (ara[i] + ara[p] >= h || flag[p] == 1 )){
                p--;
               }

            if(flag[i] + flag[p] < h){
                c++;
                flag[p] = 1;
                flag[i] = 1;
               }
                }
           // printf("%d\n",c);
            s2 = c * td;
            if(n - (2 * c) > 0)
            s2 += ((n - (2 * c)) * ta);
         //printf("%llu\n", s2);
        sum = min(s1, s2);

        printf("Case %d: %lld\n",cse, sum);
    }
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int A[131072], used[131072];
int main() {
	int testcase, cases = 0;
	scanf("%d", &testcase);
	while (testcase--) {
		int N, H, Ta, Tb;
		scanf("%d %d %d %d", &N, &H, &Ta, &Tb);
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		sort(A, A+N);

		long long ret = 0;
		memset(used, 0, sizeof(used));
		int r = N-1;
		for (int i = 0; i < N; i++) {
			if (used[i] == 1)	continue;
			while (r > i && (A[i] + A[r] >= H || used[r] == 1))
				r--;
			if (r > i && A[i] + A[r] < H && used[r] == 0 && Ta+Ta > Tb) {
				ret += Tb;
				used[r] = used[i] = 1;
			} else {
				ret += Ta;
				used[i] = 1;
			}
		}
		printf("Case %d: %lld\n", ++cases, ret);
	}
	return 0;
}
