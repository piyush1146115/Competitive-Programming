#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);

    int test;
    cin >> test;
    while(test--)
    {
        int n, m, k;


        cin >> n >> k;
        deque<int> dq;
        int mx = -1;

        for(int i = 1; i <= n; i++)
        {
            cin >> m;

            dq.push_back(m);

            if(m >= mx){
                while(dq.size() > 1){
                    dq.pop_front();
                }
                mx = m;
            }

            if(dq.size() > k){
                mx = -1;
                dq.pop_front();
                mx = *max_element(dq.begin(), dq.end());

            }


            if(i >= k)
            {
                if(i < n)
                {
                    cout << mx << " ";
                }
                else
                {
                    cout << mx << endl;
                }
            }
        }
    }

}
