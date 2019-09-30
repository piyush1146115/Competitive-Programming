#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
//freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

    int test, i, j, k,  gr, sq, n, q, l, r, rgt, lft, temp, cs = 0;
    int ara[500];

    scanf("%d", &test);


    while(test--){
        scanf("%d %d", &n,  &q);
        gr = 0;
        sq = sqrt(n);
        ara[gr] = 100000000;

        for(i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            if(i % sq == 1){
                gr++;
                ara[gr] = 100000000;
            }
            if(arr[i] < ara[gr]){
                ara[gr] = arr[i];
            }

        }
   //     cout <<arr[23] << " " << arr[24] << endl;

       printf("Case %d:\n",++cs);

        for(i = 1; i <= q; i++){
            scanf("%d %d",&l, &r);
            if(l == r)
                printf("%d\n",arr[l]);


            else{
            int ans = 1000000000;
            lft = l / sq;
            rgt = r / sq;

            if(l % sq != 0){
                lft++;
            }

            temp = lft + 1;
            lft = lft * sq;
    //        cout << l << " " << lft << " " << ans<< endl;
            for(j = l; j <= lft && j <= r; j++){
                if(arr[j] < ans){
                    ans = arr[j];
                }
            }

            for(j = temp; j <= rgt; j++){
                if(ara[j] < ans){
                    ans = ara[j];
                }
            }

            rgt *= sq;
            while(rgt < l){
                rgt++;
            }

            for(j = rgt; j <= r; j++){
                if(arr[j] < ans)
                    ans = arr[j];
            }

            printf("%d\n",ans);
            }
        }
    }
    return 0;
}
