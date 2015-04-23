#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{
	const int inf = 2000000000;
	_vertexCount = 1;
	_adjacencyMatrix = new int*[1];
	_adjacencyMatrix[1] = new int[1];
	_adjacencyMatrix[0][0] = 0;
}

Graph::Graph(int vertexCount)
{
	const int inf = 2000000000;
	_vertexCount = vertexCount;
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

Graph::Graph(ifstream &inputFile, int vertexCount)
{
	const int inf = 2000000000;
	_vertexCount = vertexCount;
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

	int firstVertex, secondVertex, weight;
	while (!inputFile.eof())
	{
		inputFile >> firstVertex;
		inputFile >> secondVertex;
		inputFile >> weight;
		_adjacencyMatrix[firstVertex][secondVertex] = weight;
		_adjacencyMatrix[secondVertex][firstVertex] = weight;
	}
}

void Graph::PrintMatrix()
{
	const int inf = 2000000000;
	for (int i = 0; i < _vertexCount; i++)
	{
		for (int j = 0; j < _vertexCount; j++)
		{
			if (_adjacencyMatrix[i][j] == inf)
			{
				cout << "inf";
			}
			else
			{
				cout << _adjacencyMatrix[i][j];
			}
			cout << '\t';
		}
		cout << endl;
	}
}