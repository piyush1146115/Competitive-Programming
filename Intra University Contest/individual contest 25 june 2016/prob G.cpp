#include<bits/stdc++.h>
using namespace std;
struct marker{
int a, b;
}in[100005], out[100005];

bool comp(marker p, marker q){
    if(p.b == q.b){
        return p.a < q.a;
    }
else
  return p.b < q.b;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int m, n, i, j, k, mn = 0, mx = 0;

    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&in[i].a, &in[i].b);
    }
    for(i = 0; i < m; i++)
        scanf("%d %d", &out[i].a, &out[i].b);

    sort(in, in + n, comp);
    sort(out, out + m, comp);
  i = 0;
  j = 0;

  while(i < n && j < m){
    if(in[i].b > out[j].b){
        j++;
    }
    else if(out[j].b > in[i].b){
        i++;
    }
    else{
        mx++;
        i++;
        j++;
    }
  }
    i = 0;
  j = 0;
   while(i < n && j < m){
    if(in[i].b > out[j].b){
        j++;
    }
    else if(out[j].b > in[i].b){
        i++;
    }
    else{
       if(in[i].a > out[j].a){
        j++;
    }
    else if(out[j].a > in[i].a){
        i++;
    }
    else{
        mn++;
        i++;
        j++;
    }
    }
  }

    cout << mx <<" " << mn << endl;

    return 0;
}
