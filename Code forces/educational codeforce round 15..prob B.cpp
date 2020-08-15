#include<bits/stdc++.h>
using namespace std;
/*long long int ara[100005];
//long long po[35];

int bin(int low, int high, int key)
{
    int mid;
    while(low <= high){
        mid = (low + high)/ 2;
        if(ara[mid] == key){
            return mid;
        }
        if(ara[mid] > key){
            high = mid - 1;
        }
        else{
        low = mid + 1;
        }
    }
    return -1;
}

int main()
{
   long long int i, j, k, n, m, ans = 0;
    long long int s, p;
    map <long long, long long int> mp;
    /*s = 1;
    for(i = 0; i <= 33; i++){
        po[i] = s;
        s *= 2;
    }

    scanf("%lld",&n);

    for(i = 0; i < n; i++){
        scanf("%lld",&ara[i]);

    }
 //sort(ara, ara + n);
/*
 for(i = 0; i < n - 1; i++){


        k = bin(i + 1, n - 1, s);
        if(k != -1){
                m = k;
                while(m > i && ara[m] == s){
                    ans++;
                    m--;
                }
                m = k + 1;
                while(m < n && ara[m] == s){
                    ans++;
                    m++;
                }
        }
         // cout << s <<" " << ans << endl;

 }
  printf("%lld\n",ans);
}
*/
int main()
{
    map<long long, long long int> mp;
    long long dif, n, i, j, m, k, ans = 0;
   // int ans = 0;
    scanf("%lld", &n);

    for(i = 0; i < n;i++){
        scanf("%lld", &k);
        for(j = 0; j <= 32; j++){
            m = 1 << j;
            m -= k;
            ans += mp[m];
        }
        mp[k]++;
    }
    cout << ans << endl;
}
