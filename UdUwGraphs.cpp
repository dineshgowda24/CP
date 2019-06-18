#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define li list<int>
#define quei queue<int>
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

/**
Class representation of an unweighted and undirected graph
bfs => breath first search
dfs => depth first search
**/
class Graph
{
	int v;
	li *adj=NULL;
	public:
		Graph(int v)
		{
			this->v=v;
			adj = new li[v];
		}
		 
		void add_edge(int v, int u)
		{
			adj[v].pb(u);
			adj[u].pb(v);
		}
		
		void bfs(int s=0)
		{
			int visited[v];
			memset(visited,0,sizeof(visited));
			quei q;
			q.push(s);
			visited[s]=1;
			while(!q.empty())
			{
				s=q.front();
				cout<<s<<" ";
				q.pop();
				for(auto i=adj[s].begin();i!=adj[s].end();++i)
				{
					if(!visited[*i])
					{
						visited[*i]=1;
						q.push(*i);
					}
				}
			}
		}
	
		void dfs_util(bool *visited, int s)
		{
			visited[s]=1;
			cout<<s<<" ";
			
			for(auto i=adj[s].begin();i!=adj[s].end();++i)
				if(!visited[*i])
					dfs_util(visited,*i);
		}
		
		/**
		Depth First Traversal of Tree
		**/
		void dfs(int s=0)
		{
			bool visited[v];
			memset(visited,0,sizeof(visited));
			dfs_util(visited,s);
		}
};

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
