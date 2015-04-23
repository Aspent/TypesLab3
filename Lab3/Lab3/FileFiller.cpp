#include "FileFiller.h"
#include <time.h>

void FileFiller::FillWithRandomEdges(ofstream &file, int vertexCount)
{
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = i + 1; j < vertexCount; j++)
		{
			int weight = rand() % 20 + 1;
			int chance = rand() % 101;
			if (chance <= 50)
			{
				file << i << " " << j << " " << weight << '\n';
			}
		}
	}
}