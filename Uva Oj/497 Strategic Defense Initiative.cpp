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
    printf("Max hits: %d\n",res);

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

int main()
{
    int n;

    scanf("%d", &n);
    getchar();
    getchar();
    string s;

    while(n--){
    len = 0;
    while(getline(cin, s)){
        //v.push_back(n);
        if(s.size() == 0)
            break;
        stringstream ss(s);
        ss >> v[len];
        len++;
    }
     longest();
     if(n)
        printf("\n");
    }
}
