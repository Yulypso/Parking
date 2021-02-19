#include "main.h"

/************************* Décoration étoile/neige ************************/
void STARS(int MaxY, int MaxX)
{
	int TAB[MaxY][MaxX];

	for(int i=0; i<MaxY; i++)
	{
		for(int j=0; j<MaxX; j++)
		{
			TAB[i][j]=rand();
		}
	}

	for(int i=0; i<MaxY; i++)
	{
		for(int j=0; j<MaxX; j++)
		{
			if(TAB[i][j]%450 == 0)
			{
				mvaddch(i, j, '*');
			}
		}
	}
}

