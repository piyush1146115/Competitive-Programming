#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    int a, b, c, d;
    int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    vector<int> v1, v2;
    char str[6][4];

   /* str[0] = { 'B', 'C', 'G', '\0'};
    str[1] = { 'B', 'G', 'C', '\0' };
    str[2] = { 'C', 'B', 'G', '\0' };
    str[3] = { 'C', 'G', 'B', '\0' };
    str[4] = { 'G', 'B', 'C', '\0' };
    str[5] = { 'G', 'C', 'B', '\0' };
*/
    while(scanf("%d %d %d %d %d %d %d %d %d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) == 9){
        v1.push_back(g1 + c1 + b2 + g2 + b3 + c3);
        v1.push_back(g1 + c1 + b2 + c2+ b3 + g3);
        v1.push_back(b1 + g1 + g2 + c2+ b3 + c3);
        v1.push_back(b1 + g1 + b2 + c2 + g3 + c3);
        v1.push_back(b1 + c1 + g2 + c2 + b3 + g3);
        v1.push_back(b1 + c1 + g2 + b2 + g3 + c3);

        v2 = v1;// copying

        sort(v2.begin(), v2.end());

       if(v2[0] == v1[0]){
        printf("BCG %d\n",v2[0]);
       }
       else if(v2[0] == v1[1]){
        printf("BGC %d\n",v2[0]);
       }
       else if(v2[0] == v1[2]){
        printf("CBG %d\n",v2[0]);
       }

       else if(v2[0] == v1[3]){
        printf("CGB %d\n",v2[0]);
       }

       else if(v2[0] == v1[4]){
        printf("GBC %d\n",v2[0]);
       }

      else if(v2[0] == v1[5]){
        printf("GCB %d\n",v2[0]);
       }
       v1.clear();
       v2.clear();
    }
    return 0;
}
