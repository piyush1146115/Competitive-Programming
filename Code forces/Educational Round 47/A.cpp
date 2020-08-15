#include<bits/stdc++.h>
using namespace std;
int c[1005], a[1005];

int main()
{
    int n, m;

    cin >> n >> m;

    for(int i = 0;i < n; i++){
        cin >> c[i];
    }

    queue<int> q;
    for(int i = 0;i < m; i++){
        cin >> a[i];
        q.push(a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(q.empty()){
            continue;
        }
        int temp = q.front();

        if(temp >= c[i]){
            q.pop();
            cnt++;
        }
    }

    cout << cnt << endl;
}
