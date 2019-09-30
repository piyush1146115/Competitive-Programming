#include<bits/stdc++.h>
using namespace std;
#define mxx 50005
vector<int> v;

int main()
{
 int test;

 scanf("%d" , &test);

 for(int tc = 1; tc <= test; tc++){
    int r, c;

    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int k;
            scanf("%d", &k);
            int dif = (r - 1 - i) + (c - 1 - j);
            if(dif % 2 == 1)
                v.push_back(k);
        }
    }
   int ans = 0;
   for(int i = 0; i < (int)v.size(); i++)
        ans ^= v[i];
   if(ans != 0)
    printf("Case %d: win\n",tc);
   else
    printf("Case %d: lose\n",tc);

   v.clear();
 }

}
