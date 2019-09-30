#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n, a;

    scanf("%lf %lf", &n, &a);

    double angle = 180.0/n;

    int ans;
    double sum = 0.0, minn= 50000.0;

    for(int i = 3; i <= n;i++){
        sum += angle;
        double diff = abs(sum - a);
        if(diff < minn){
            minn = diff;
            ans = i;
        }
    }

    cout << "2 1 " << ans << endl;
}
