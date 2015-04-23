#include "FileFiller.h"
#include "graph.h"

#include <iostream>

using namespace std;

void main(int argc, char *argv[])
{
	cout << "Input count of vertexes" << endl;
	int count;
	cin >> count;
	ofstream file(argv[1]);
	ofstream outputFile(argv[2]);
	ofstream errorFile(argv[3]);

	FileFiller fileFiller;
	try
	{
		fileFiller.FillWithRandomEdges(file, count);
	}
	catch (invalid_argument error)
	{
		cout << error.what() << endl;
		errorFile << error.what() << endl;
	}
	file.close();

	ifstream inputFile(argv[1]);
	
	Graph graph;
	try
	{
		graph = Graph(inputFile, count);
		graph.PrintMatrix();
		Graph minTree = graph.GetMinSpanningTree();
		cout << "Edges of minimum spanning tree:" << endl;
		minTree.PrintEdges();
		minTree.WriteEdgesInFile(outputFile);	
	}
	catch (invalid_argument error)
	{
		cout << error.what() << endl;
		errorFile << error.what() << endl;
	}

	inputFile.close();
	outputFile.close();
	errorFile.close();

	system("pause");
}
