#include <bits/stdc++.h>

using namespace std;

typedef int vertice;
typedef int weight;
typedef vector<pair<weight, vertice>> adj;
typedef pair<int, int> node;

#define WHITE 0
#define YELLOW 1
#define BLACK 2


void dijkstra(vector<adj> &graph, int n_vertices, int start){
  int distance[n_vertices];
  int pi[n_vertices];
  int color[n_vertices];

  for(int i = 0; i < n_vertices; i++){
      distance[i] = 1e9;
      pi[i] = -1;
      color[i] = WHITE;
  }

  priority_queue<node, vector<node>, greater<node> > q; // min heap

  q.push({0, start});
  distance[start] = 0;
  
  while(!q.empty()){
    int v = q.top().second;
    int wv = q.top().first;
    
    q.pop();

    for(int i = 0; i < graph[v].size(); i++) {
      int u = graph[v][i].second;
      int wu = graph[v][i].first;

      if(distance[u] > wv + wu) {
        distance[u] = wv + wu;
        pi[u] = v;
        q.push({distance[u], u});
      }
    }
  }
}

int main(){
  vector<adj> graph;
	int n_vertices, n_edges;
	
	cin>>n_vertices;
	cin>>n_edges;
	
	graph.resize(n_vertices);
	
	for(int i = 0, w, from, to; i < n_edges; i++){
		cin>>from>>to>>w;
		from--;
		to--;
		graph[from].push_back({w, to});
	}	
	return 0;
}
