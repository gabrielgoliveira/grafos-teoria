#include <bits/stdc++.h>

using namespace std;

typedef vector<int> adj;

#define WHITE 0
#define YELLOW 1
#define BLACK 2 

void bfs(vector<adj> &graph, int n_vertices, int s) {
	queue<int> q;
	
	int color[n_vertices];
	int distance[n_vertices];
	int pi[n_vertices];
	
	for (int i = 0; i < n_vertices; i++) {
		color[i] = WHITE;
		pi[i] = -1;
		distance[i] = 1e9;
	}
	
	distance[s] = 0;
	color[s] = YELLOW;
	
	q.push(s);
	
	while(!q.empty()){
		int front = q.front(); 
		q.pop();
		
		for (int i = 0; i < graph[front].size(); i++) {
			int u = graph[front][i]; 
			if(color[u] != WHITE) {
				color[u] = YELLOW;
				d[u] = d[front] + 1;
				pi[u] = front;
				q.push(u);
			}
		}
		
		color[front] = BLACK;	
	}
	
	for (int i = 0; i < n_vertices; i++) {
		cout<"Distance from "<<i<<" to "i+1<<distance[i+1];
	}
	
	return ;
}

int main(){
	vector<adj> graph;
	int n_vertices, n_edges;
	
	cin>>n_vertices
	cin>>n_edges;
	
	graph.resize(n_vertices);
	
	for(int i = 0, from, to; i < n_edges; i++){
		cin>>from>>to;
		from--;
		to--;
		graph[from].push(to);
	}
	
	
	return 0;
}
