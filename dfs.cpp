#include <bits/stdc++.h>

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

using namespace std;

typedef int valor;
typedef int indice_vertice;
typedef vector<pair<valor, indice_vertice >> node; // chave ou peso do vertice e o id do vertice

void profundidadeDFS(vector<node> &grafo, int vertice_atual, int *cor) {
  cor[vertice_atual] = AMARELO;
  cout<<"Vetor coloracao : "<<endl;
  for(int i = 0; i < grafo.size(); i++) {
    cout<<cor[i]<<" ";
  }
  cout<<endl;
  vector<pair<int, int>> adjacencia = grafo[vertice_atual];
  
  for(int i = 0; i < adjacencia.size(); i++) {
    int vertice = adjacencia[i].second; // recuperando o indice do vertice
    if(cor[vertice] == BRANCO) {
      profundidadeDFS(grafo, vertice, cor);
    }
  }
  cor[vertice_atual] = VERMELHO;
}

void dfs(vector<node> &grafo, int n_vertices){
  cout<<"O grafo recebido foi : "<<endl;
  for (int i = 0; i < n_vertices; i++) {
    cout<<i<<" -> ";
    for (int j = 0; j < grafo[i].size(); j++) {
      cout<<grafo[i][j].second<<" ";
    }
    cout<<endl;
  }

  int cor[n_vertices];

  for(int i = 0; i < n_vertices; i++){
    cor[i] = BRANCO;
  }

  for(int i = 0; i < n_vertices; i++) {
    if(cor[i] == BRANCO) {
      profundidadeDFS(grafo, i, cor);
    }
  }

  cout<<"Vetor coloracao : "<<endl;
  for(int i = 0; i < grafo.size(); i++) {
    cout<<cor[i]<<" ";
  }
}

int main () {
  vector <node> grafo;
  int n_vertices, n_arestas;
  cout<<"Insira a quantidade de vertices : ";
  cin>>n_vertices;

  grafo.resize(n_vertices);

  cout<<"Insira a quantidade de arestas : ";
  cin>>n_arestas;

  for (int i = 0; i < n_arestas; i++) {
    int de, para;
    cout<<"Lendo a aresta : "<<i+1<<endl;
    cout<<"Insira a Origem e o Destino : ";
    cin>>de>>para;
    grafo[de].push_back({1, para});
  }

  dfs(grafo, n_vertices);
}
