#include<bits/stdc++.h>
using namespace std;

struct node{
	int at, cost;
	node(int _at, int _cost){
		at = _at;
		cost = _cost;
	}
}

bool operator < (node a, node b)
{
	return a.cost > b.cost;
}

struct edge{
	int v, w;
	edge(int _v, int _w){
		v = _v;
		w = _w;
	}
}

vector<edge> adj[100];//list of weighted edges

int main()
{
}
