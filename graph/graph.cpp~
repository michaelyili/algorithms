#include <iostream>
using namespace std;

//typedef int Type;

struct gNode {
	int v;
	float weight;
	gNode* next;
	gNode(int x, float w, gNode* t): v(x), weight(w), next(t) {}
};

struct GRAPH {
	int Vcnt, Ecnt;
	bool digraph;
	gNode **adj;
	bool *visited;
};

void initG(GRAPH* &G, int V, bool dig) {
	G->adj = new gNode*[V];
	G->Vcnt = V;
	G->Ecnt = 0;
	G->digraph = dig;
	G->visited = new bool[V];
	for(int i=0; i<V; ++i) {
		G->visited[i] = false;
	}
}


int main(int argc, char* argv[])
{
	return 0;
}
