#include "FileFiller.h"
#include "graph.h"
#include <iostream>

using namespace std;

void main()
{
	ofstream file("input.graph");
	FileFiller fileFiller;
	fileFiller.FillWithRandomEdges(file, 6);
	file.close();
	ifstream inputFile("input.graph");
	
	Graph graph(inputFile, 6);
	graph.PrintMatrix();

	Graph minTree = graph.GetMinSpanningTree();
	//cout << endl;
	//minTree.PrintMatrix();
	cout << "Edges of minimum spanning tree:" << endl;
	minTree.PrintEdges();

	inputFile.close();
	system("pause");
}
