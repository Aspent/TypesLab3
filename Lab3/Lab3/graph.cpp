#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{
	const int inf = 2000000000;
	_vertexCount = 1;
	_adjacencyMatrix = new int*[1];
	_adjacencyMatrix[0] = new int[1];
	_adjacencyMatrix[0][0] = 0;
}

Graph::Graph(int vertexCount)
{
	if (vertexCount < 1)
	{
		throw invalid_argument("Wrong count of vertexes");
	}
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
	if (vertexCount < 1)
	{
		throw invalid_argument("Error in initialization of graph: Wrong count of vertexes");
	}
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
		_adjacencyMatrix[firstVertex-1][secondVertex-1] = weight;
		_adjacencyMatrix[secondVertex-1][firstVertex-1] = weight;
	}
}

int Graph::GetVertexCount()
{
	return _vertexCount;
}

int** Graph::GetAdjancencyMatrix()
{
	return _adjacencyMatrix;
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

Graph Graph::GetMinSpanningTree()
{
	const int inf = 2000000000;
	Graph minTree(_vertexCount);

	bool* isMarked = new bool[_vertexCount];
	for (int i = 0; i < _vertexCount; i++)
	{
		isMarked[i] = false;
	}

	isMarked[0] = true;
	
	for (int k = 0; k < _vertexCount-1; k++)
	{

		int min = inf;
		int firstVertOfMin = -1;
		int secondVertOfMin = -1;

		for (int i = 0; i < _vertexCount; i++)
		{
			if (isMarked[i])
			{
				for (int j = 0; j < _vertexCount; j++)
				{
					if (!isMarked[j])
					{
						if (_adjacencyMatrix[i][j] < min)
						{
							min = _adjacencyMatrix[i][j];
							firstVertOfMin = i;
							secondVertOfMin = j;
						}
					}
				}
			}
		}
		isMarked[secondVertOfMin] = true;
		//cout << firstVertOfMin + 1 << "-" << secondVertOfMin + 1 << "  " << min << endl;
		minTree._adjacencyMatrix[firstVertOfMin][secondVertOfMin] = min;
		minTree._adjacencyMatrix[secondVertOfMin][firstVertOfMin] = min;
	}

	return minTree;
}

void Graph::PrintEdges()
{
	const int inf = 2000000000;
	for (int i = 0; i < _vertexCount; i++)
	{
		for (int j = i + 1; j < _vertexCount; j++)
		{
			if (_adjacencyMatrix[i][j] != inf)
			{
				cout << i + 1 << "-" << j + 1 << "  " << _adjacencyMatrix[i][j] << endl;
			}
		}
	}
}

void Graph::WriteEdgesInFile(ofstream &file)
{
	const int inf = 2000000000;
	for (int i = 0; i < _vertexCount; i++)
	{
		for (int j = i + 1; j < _vertexCount; j++)
		{
			if (_adjacencyMatrix[i][j] != inf)
			{
				file << i + 1 << " " << j + 1 << " " << _adjacencyMatrix[i][j] << endl;
			}
		}
	}
}