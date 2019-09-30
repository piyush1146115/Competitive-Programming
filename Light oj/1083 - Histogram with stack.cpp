#include<bits/stdc++.h>
using namespace std;
#define mxx 30005
int lf[mxx], rh[mxx];

int main() {

    int test;

    scanf("%d", &test);

    for (int tc = 1; tc <= test; tc++) {
        vector<int> v;


        v.push_back(0);
        int n;

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            v.push_back(k);
        }

        //res.push_back(0);

        stack<int> st;
        st.push(0);

        for (int i = 1; i < (int)v.size(); i++) {
            while (v[st.top()] >= v[i]) {
                st.pop();
            }
            lf[i] = st.top();

            st.push(i);
        }

        v.push_back(0);
        //  rh.push_back(0);

        while (!st.empty())
            st.pop();

        st.push(n + 1);

        for (int i = n; i >= 1; i--) {
            while (v[st.top()] >= v[i]) {
                st.pop();
            }
            rh[i] = st.top();
            st.push(i);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int dif = (i - lf[i]) + (rh[i] - i) - 1;
            int res = dif * v[i];
            //  cout << i << " " <<v[i] << " " << lf[i] << " "<< v[lf[i]] << " " << rh[i] << " " << v[rh[i]] <<" " << res << endl;
            ans = max(ans, res);
        }

        printf("Case %d: %d\n", tc, ans);
    }
}
