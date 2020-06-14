#include<bits/stdc++.h>
using namespace std;
#define mxx 205

struct edge{
int u, v, w;
};

vector<edge> E;
int dist[mxx];

int n;

void bellmanford(int s)
{
    for(int i = 1; i <= n; i++){
        dist[i] = 1000000000;
    }
    dist[s] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < (int)E.size(); j++){
            edge e = E[j];
            if(dist[e.v] > dist[e.u] + e.w){
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
}

int main()
{

}
