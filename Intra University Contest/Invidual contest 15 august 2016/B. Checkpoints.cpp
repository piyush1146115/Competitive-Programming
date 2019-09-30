#include<bits/stdc++.h>
using namespace std;
int a;
bool comp(int x, int y)
{
    return abs(x - a) < abs(y - a);
}
int main()
{
    vector<int> left, rgt;
    int n, i, j, k ,ans[10];

    scanf("%d %d", &n, &a);

    for(i = 0; i < n; i++){
        scanf("%d",&k);
        if(k > a){
            rgt.push_back(k);
        }
        else{
            left.push_back(k);
        }
    }
    if(n == 1)
        cout << "0\n";

    else if(left.size() == 0&& n > 1){
    cout << abs(rgt[rgt.size() - 1]  - a) << endl;
    }
    else if(rgt.size() == 0 && n > 1){
        cout << abs(a - left[1]) << endl;
    }

    else{

            if(rgt.size() > 1 && left.size() > 1){
    ans[0] = abs(rgt[rgt.size() - 1]  - a) * 2 + abs(left[1] - a);
    ans[1] = abs(rgt[rgt.size() - 2] - a) * 2 + abs(left[0] - a);
    ans[2] = abs(left[1] - a) * 2 + abs(rgt[rgt.size() - 1]  - a);
    ans[3] = abs(rgt[rgt.size() - 2] - a) + abs(left[0] - a)*2;
    sort(ans, ans + 4);
    cout << ans[0] << endl;
            }
            else if(rgt.size() == 1 && left.size() == 1){
                cout << min(abs(left[0] - a), abs(rgt[0] - a));
            }
            else if(rgt.size() == 1){
                cout << min((abs(rgt[0] - a) * 2 + abs(left[1] - a)),  abs(left[0] - a));
            }
            else if(left.size() == 1){
                   cout << min((abs(left[0] - a) * 2 + abs(rgt[rgt.size() - 2] - a)),  abs(rgt[rgt.size() - 1] - a));
            }
    }
}
