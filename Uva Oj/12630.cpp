/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans;

    while(scanf("%d", &n) == 1 && n != 0){
        ans = ((n * (n - 1)) / 2) + (((n - 1) * (n - 2)) / 2);
        if(n > 2)
            ans++;

        cout << ans << endl;
    }
    return 0;
}
*/
#include<stdio.h>
int n;
int main(){
	scanf("%d",&n);
	while(n){
		printf("%d\n",(n+2)*(n+1)*n*(n-1)/24);
		scanf("%d",&n);
	}
}
