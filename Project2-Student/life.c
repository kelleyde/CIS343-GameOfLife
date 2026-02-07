//***************************************************
// Filename: life.c
//
// Author(s):
//***************************************************

#include "life.h"

// Constructs and returns a string representation of the grid (for display/testing purposes)
// DO NOT MAKE ANY CHANGES TO THIS FUNCTION
char *toString(int rows, int cols, char **grid)
{
	char *str = (char *)calloc(4 * rows * cols, sizeof(char));
	char *ptr = str;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] == '0')
			{
				sprintf(ptr, " . ");
			}
			else
			{
				sprintf(ptr, " X ");
			}
			ptr += 3;
		}
		sprintf(ptr, "\n");
		ptr++;
	}

	return str;
}

// Creates a grid of rows x cols and initializes the grid with data from specified file
// Note: grid is a two-dimensional array of single characters
char **loadGridFromFile(char *filename, int *rows, int *cols)
{
	char **grid = NULL;
	char buf[1024]; // max length of line in input file
	FILE *file = fopen(filename, "r");

	// read line from file
	fgets(buf, 1024, file);
	fclose(file);

	// get number of rows from the line read
	*rows = atoi(strtok(buf, " "));

	// get number of columns from the line read
	*cols = atoi(strtok(NULL, " "));

	// COMPLETE THIS PART OF THIS FUNCTION

	return grid;
}

// Saves the grid data to the specified file
void saveGridToFile(char *filename, int rows, int cols, char **grid)
{
	FILE *file = fopen(filename, "w");

	// COMPLETE THIS PART OF THIS FUNCTION

	fclose(file);
}

// Creates and returns a new grid that is a duplicate of the given grid
char **copyGrid(int rows, int cols, char **grid)
{
	char **dup = NULL;

	// COMPLETE THIS PART OF THIS FUNCTION

	return dup;
}

// Mutates the given grid one generation and return a new grid
char **mutateGrid(int rows, int cols, char **grid)
{
	char **newgrid = copyGrid(rows, cols, grid);

	// COMPLETE THIS PART OF THIS FUNCTION

	return newgrid;
}

// Returns the number of neighbors at postion (i,j) in the grid
int nbrOfNeighbors(int i, int j, int rows, int cols, char **grid)
{
	int neighbors = 0;

	// COMPLETE THIS PART OF THIS FUNCTION

	return neighbors;
}
