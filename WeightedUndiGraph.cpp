#include <bits/stdc++.h>
using namespace std;

//This is an weighted and undirected graph
class Graph{
	list<pair<int,int>> *adj;
	int V;
	public:
		Graph(int V){
			this->V = V;
			//init the vector for so many nodes
			adj = new list<pair<int,int>>[V];
		}
		
		void addEdge(int u, int v, int wt){
			adj[u].push_back({v,wt});
			adj[v].push_back({u,wt});
		}
		
		void print(){
			//for every vertex 
			for(int i=0;i<V;++i){
				//go through every edge
				cout<<"Vertex "<<i<<" has edge with : ";  
				for(auto it = adj[i].begin(); it != adj[i].end();it++){
					cout<<it->first<<" of weight "<<it->second<<" ; ";
				}
				cout<<endl;
			}
		}
		
		void bfs(int i=0){
			bool visited[V];
			memset(visited, 0, sizeof(visited));
		
			queue<int> nodes;
			nodes.push(i);
			visited[i]=1;
			
			while(!nodes.empty()){
				int node = nodes.front();
				nodes.pop();
				cout<<node<<" ";
				for(auto it = adj[node].begin();it != adj[node].end();++it){
					if(!visited[it->first]){
						nodes.push(it->first);
						visited[it->first]=1;
					}
				}
			}
		}
		
		void dfs(int i=0){
			stack<int> s;
			s.push(i);
			bool visited[V];
			memset(visited,0,sizeof(visited));
			visited[i]=1;
			while(!s.empty()){
				int node = s.top();
				s.pop();
				
				cout<<node<<" ";
				
				for(auto it = adj[node].begin();it != adj[node].end(); ++it){
					if(!visited[it->first]){
						s.push(it->first);
						visited[it->first]=1;
					}
				}
			}
		}
		
		//By default the node rooted at 0 is assumned to be level 0
		//levels is array of size V, which would indicate the levels of all the node
		void bfs(int *levels, int i=0){
			bool visited[V];
			memset(visited, 0, sizeof(visited));
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			levels[i] = 0;
			
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(auto it = adj[node].begin();it!=adj[node].end();++it){
					if(!visited[it->first]){
						levels[it->first] = levels[node] + 1;
						visited[it->first] = 1;
						q.push(it->first);
 					}
				}
			}
		}
};

int main() {
	// your code goes here
	Graph g(5);
	g.addEdge(1,4,21);
	g.addEdge(1,3,12);
	g.addEdge(2,3,22);
	g.addEdge(0,4,51);
	g.addEdge(4,3,17);
	g.addEdge(1,2,33);
	g.addEdge(3,0,91);
	g.addEdge(0,1,11);
	// g.print();
	g.bfs();
	cout<<endl;
	g.dfs();
	int levels[5];
	g.bfs(levels);
	cout<<endl;
	for(int i=0;i<5;++i)
		cout<<"Vertex "<<i<<" is at level "<<levels[i]<<endl;
	return 0;
}
