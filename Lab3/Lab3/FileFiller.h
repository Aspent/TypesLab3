#ifndef _FileFiller_h
#define _FileFiller_h

#include <fstream>

using namespace std;

class FileFiller
{
public:
	void FillWithRandomEdges(ofstream &file, int vertexCount);
};


#endif