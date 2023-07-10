#include <stdlib.h>
#include "main.h"
/**
 * free_grid - frees a 2 dimensional grid previously created
 * @grid: pointer to the array
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
	int i, j;
	int width = (&grid[1] - grid) / sizeof(int);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			free(grid[i][j]);
	}
}
