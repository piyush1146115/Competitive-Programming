#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005

int L[MAX], R[MAX];

int main()
{
    int n, m;

    while(scanf("%d %d",&n, &m) == 2){
        if(m == 0 && n == 0){
            break;
        }
        for(int i = 1; i <= n; i++){
            L[i] = i - 1;
            R[i] = i + 1;
        }

        for(int i = 1; i <= m; i++){
                int l, r;
//            for(int j = 1;j <= n; j++){
//                printf("left  of %d >>> %d Right  of %d >>> %d\n",j, L[j], j, R[j]);
//            }

            scanf("%d %d",&l, &r);
            if(L[l] == 0){
                printf("*");
            }
            else{
                printf("%d", L[l]);
            }
            if(R[r] == n + 1){
                printf(" *\n");
            }
            else{
                printf(" %d\n",R[r]);
            }
            R[L[l]] = R[r];
            L[R[r]] = L[l];
        }
        printf("-\n");
    }
}
