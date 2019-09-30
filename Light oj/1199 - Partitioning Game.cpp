#include<bits/stdc++.h>
using namespace std;
#define mxx 10005
int dp[mxx], ara[mxx];
int cnt = 0;

int calculateMEX(set<int> Set){
int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

int fun(int n)
{
	if(n <= 2)
	return 0;

	if(dp[n] != -1)
	return dp[n];

	set<int> Set;
	for(int i = 1;i < (n - i);i++){

		Set.insert(fun(i) ^ fun(n - i));
	}

	dp[n] = calculateMEX(Set);
	return dp[n];
}

int main()
{
		int test;
		scanf("%d", &test);
		memset(dp, -1, sizeof(dp));

		for(int tc = 1; tc <= test; tc++){
			int n;
			scanf("%d", &n);

			for(int i = 0 ; i < n; i++){
				scanf("%d", &ara[i]);
			}

			for(int i = 0; i < n; i++){
				ara[i] = fun(ara[i]);
			}

			int ans = 0;
			for(int i = 0; i < n; i++){
				ans ^= ara[i];
			}

			if(ans != 0){
				printf("Case %d: Alice\n", tc);
			}
			else{
				printf("Case %d: Bob\n", tc);
			}
		}

		return 0;
}
