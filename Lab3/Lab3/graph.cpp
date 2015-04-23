#include "graph.h"

using namespace std;

Graph::Graph()
{
	const int inf = 2000000000;
	_adjacencyMatrix = new int*[1];
	_adjacencyMatrix[1] = new int[1];
	_adjacencyMatrix[0][0] = 0;
}

Graph::Graph(int vertexCount)
{
	const int inf = 2000000000;
	_adjacencyMatrix = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		_adjacencyMatrix[i] = new int[vertexCount];
	}
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
		{			
			_adjacencyMatrix[i][j] = inf;
		}
	}
}