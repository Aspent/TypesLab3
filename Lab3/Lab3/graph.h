#ifndef graph_h
#define graph_h
#include <fstream>

using namespace std;

class Graph
{
private:
	int** _adjacencyMatrix;

public:
	Graph();
	Graph(int vertexCount);
	Graph(ifstream inputFile);

	Graph GetMinSpanningTree();
};



#endif