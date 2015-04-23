#include "FileFiller.h"
#include <time.h>

void FileFiller::FillWithRandomEdges(ofstream &file, int vertexCount)
{
	srand(time(NULL));
	if (vertexCount < 1)
	{
		throw invalid_argument("Error in filling file: Wrong count of vertexes");
	}
	for (int i = 1; i <= vertexCount; i++)
	{
		for (int j = i + 1; j <= vertexCount; j++)
		{
			int weight = rand() % 20 + 1;
			int chance = rand() % 101;
			if (chance <= 75)
			{
				file << i << " " << j << " " << weight << '\n';
			}
		}
	}
}