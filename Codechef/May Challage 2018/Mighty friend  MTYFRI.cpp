#include<bits/stdc++.h>
using namespace std;
#define MAX 10005

int main()
{
    int test;
    scanf("%d", &test);

    while(test--)
    {
        vector<int> odd, even;
        int n, k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            if(i % 2 == 0)
            {
                odd.push_back(m);
            }
            else
            {
                even.push_back(m);
            }
        }

        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int ev = 0, od = 0;
        for(int i = 0; i < even.size(); i++)
        {
            //cout << even[i] << endl;
            ev += even[i];
        }
        for(int  i = 0; i < odd.size(); i++)
        {
            od += odd[i];
        }

        for(int i = 0; i < k && i < even.size(); i++)
        {
            if(even[i] < odd[i])
            {
                od -= odd[i];
                od += even[i];
                ev -= even[i];
                ev += odd[i];
            }
        }

        if(ev > od)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        odd.clear();
        even.clear();
    }
}
