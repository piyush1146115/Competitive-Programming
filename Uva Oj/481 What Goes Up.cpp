#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int v[100005];
int ans ;
//int dp[10005];
int I[100005], L[100005];
int len;

void reset()
{
    I[0] = -inf;

    for(int i = 1; i <= len; i++)
        I[i] = inf;

}

void longest()
{
 reset();
    //cout << "ok\n";

    for(int i = 0; i < len; i++){

        int k = v[i];

        int lo = 0, hi = len - 1,mid, ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if( k > I[mid]){
                ans = mid + 1;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

            L[i] = ans;
            I[ans] = k;
    }

    int res = 0;
    for(int i = 0; i < len; i++)
        res = max(res, L[i]);

    //cout << res << endl;
    printf("%d\n-\n",res);
    vector<int> vec;
    for(int i = len - 1; i >= 0; i--){
        if(L[i] == res){
            vec.push_back(v[i]);
            //printf("%d\n",v[i]);
            res--;
        }
    }

    for(int i = vec.size() - 1; i >= 0; i--)
        printf("%d\n",vec[i]);

    vec.clear();
}

//
//void path(int ind)
//{
//    printf("%d\n",v[ind]);
//
//    while(dir[ind] != -1){
//        printf("%d\n",v[dir[ind]]);
//        ind = dir[ind];
//    }
//}


int main()
{
    int n;
//    memset(dp, -1, sizeof(dp));
  //  memset(dir, -1, sizeof(dir));
    len = 0;
    while(scanf("%d", &v[len]) == 1){
        //v.push_back(n);
        len++;
    }

     longest();


    //cout << ans << endl;
   // printf("-\n");
    //path(ind);
  //  v.clear();
}
