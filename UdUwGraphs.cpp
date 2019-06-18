#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define li list<int>
using namespace std;

//Unweighted and undirected
//So we need to add the direction in both the ways
void add_edge(vi *graph,int v,int u)
{
	graph[v].pb(u);
	graph[u].pb(v);
}

void print_graph(vi *g, int v)
{
	for(int i=0;i<v;++i)
	{
		cout<<"Vertex "<<i<<" has edge with vertex : ";
		for(int j=0;j<g[i].size();++j)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}

int main() {
	int v=5;
	vi graph[5];
	add_edge(graph,0,1);
	add_edge(graph,0,4);
	add_edge(graph,1,2);
	add_edge(graph,1,4);
	add_edge(graph,2,3);
	add_edge(graph,3,0);
	add_edge(graph,4,2);
	print_graph(graph,v);
	return 0;
}
