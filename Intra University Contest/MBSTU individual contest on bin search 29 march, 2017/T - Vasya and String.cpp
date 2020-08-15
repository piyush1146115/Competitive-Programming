#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int n, k, sum_a[mxx], sum_b[mxx];
string s;

void  cum()
{
    int cnt_a = 0, cnt_b = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'a')
            cnt_a++;
        else
            cnt_b++;

        sum_a[i] = cnt_a;
        sum_b[i] = cnt_b;

    //    cout << sum_a[i] << " " << sum_b[i] << endl;
    }
}
int calc_a()
{
    int ans = 1, a = -1, b = 0, j = 1;

    for(int i = 0, j = 0; i < n; i++){
        while(j <= i){
            b = sum_b[i] - sum_b[j - 1];

            if(b > k)
                j++;
            else
                break;
        }

        if(b <= k){
        ans = max(ans, (i - j + 1));
    }
    }
    return ans;
}

int calc_b()
{
    int ans = 1, a = 0, b = -1, j = 1;

    for(int i = 0, j = 0; i < n; i++){
        while(j <= i){
            a = sum_a[i] - sum_a[j - 1];

            if(a > k)
                j++;
            else
                break;
        }

        if(a <= k){
        ans = max(ans, (i - j + 1));
    }
    }
    return ans;
}

int main()
{
    scanf("%d %d",&n, &k);
    cin >> s;
    cum();

    int ans = max(calc_a(), calc_b());

    cout <<ans << endl;
}
