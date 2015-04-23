#ifndef graph_h
#define graph_h
#include <fstream>

using namespace std;

class Graph
{
private:
	int _vertexCount;
	int** _adjacencyMatrix;

public:
	Graph();
	Graph(int vertexCount);
	Graph(ifstream &inputFile, int vertexCount);
	int GetVertexCount();
	int** GetAdjancencyMatrix();
	void PrintMatrix();
	Graph GetMinSpanningTree();
	void PrintEdges();
	void WriteEdgesInFile(ofstream &file);
};



#endif