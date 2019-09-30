#include<bits/stdc++.h>
using namespace std;

struct st{
int w, iq;
}ara[1005];

int n = 0;

int lcs(int i, int j)
{
  //  cout << " ok " << endl;
  cout << i << " " << j << endl;
  getchar();

    if(i == n || j == n || i < 0 || j < 0)
        return 0;

    int ret = 0;

    if(ara[i].w > ara[j].w && ara[i].iq < ara[j].iq){

          //  ret = max(ret, 1 + lcs(j, j + 1));
            ret =max(ret, 1 + lcs(j, j - 1));
    }
    else{
        ret = max(ret, lcs(i, j + 1));
        ret = max(ret, lcs(i + 1, j + 1));
        //ret = max(ret, lcs(i, j - 1));
    }
    return ret;
}

int main()
{
    int p, q;

    while(scanf("%d %d", &p, &q) == 2){
        ara[n].w = p;
        ara[n].iq = q;
        n++;
    }
    cout << lcs(0, 0) << endl;
}
