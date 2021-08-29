#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int test;

    cin >> test;

    for(int tc = 1; tc <= test; tc++)
    {
        int sz, n, k;

        cin >> sz >> n;

        deque<int> dq;
        cout << "Case " << tc << ":" << endl;

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            if(s == "pushLeft")
            {
                cin >> k;
                if(dq.size() < sz)
                {
                    dq.push_front(k);
                    cout << "Pushed in left: " << k << endl;
                }
                else
                {
                    cout << "The queue is full" << endl;
                }
            }
            else if(s == "pushRight")
            {

                cin >> k;
                if(dq.size() < sz)
                {
                    dq.push_back(k);
                    cout << "Pushed in right: " << k << endl;
                }
                else
                {
                    cout << "The queue is full" << endl;
                }
            }
            else if(s == "popLeft")
            {
                if(dq.size() > 0)
                {

                    cout << "Popped from left: " << dq.front() << endl;
                    dq.pop_front();
                }
                else
                {
                    cout << "The queue is empty" << endl;
                }
            }
            else
            {
                if(dq.size() > 0)
                {
                    cout << "Popped from right: " << dq.back() << endl;
                    dq.pop_back();
                }
                else{
                    cout << "The queue is empty" << endl;
                }

            }

        }
    }
}
