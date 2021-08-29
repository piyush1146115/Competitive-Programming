#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    int tp;
    long long k;
    set<long long> st;

    for(int i = 0; i < n; i++)
    {
        cin >> tp >> k;

        if(tp == 1)
        {
            st.insert(k);
        }
        else if(tp == 2)
        {
            if(st.find(k) != st.end())
                st.erase(k);
        }
        else
        {
            if(st.find(k) != st.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}
