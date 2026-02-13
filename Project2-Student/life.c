//***************************************************
// Filename: life.c
//
// Author(s):
// jeni and daleney

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

	if (file == NULL)
		return NULL;

	
	if (fgets(buf, 1024, file) == NULL)
	{
		fclose(file);
		return NULL;
	}
	fclose(file);

	// get number of rows from the line read
	*rows = atoi(strtok(buf, " "));

	// get number of columns from the line read
	*cols = atoi(strtok(NULL, " "));

	// COMPLETE THIS PART OF THIS FUNCTION

	// reopen the file and read rows/cols 
	file = fopen(filename, "r");
	if (file == NULL)
		return NULL;

	if (fscanf(file, "%d %d", rows, cols) != 2 || *rows <= 0 || *cols <= 0)
	{
		fclose(file);
		return NULL;
	}

	// allocate memory
	grid = (char **)malloc((*rows) * sizeof(char *));
	if (grid == NULL)
	{
		fclose(file);
		return NULL;
	}

	for (int i = 0; i < *rows; i++)
	{
		grid[i] = (char *)malloc((*cols) * sizeof(char));
		if (grid[i] == NULL)
		{
			for (int k = 0; k < i; k++)
				free(grid[k]);
			free(grid);
			fclose(file);
			return NULL;
		}
	}

	// read grid values
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			int value;
			if (fscanf(file, "%d", &value) != 1 || (value != 0 && value != 1))
			{
				for (int r = 0; r < *rows; r++)
					free(grid[r]);
				free(grid);
				fclose(file);
				return NULL;
			}
			grid[i][j] = (value == 0) ? '0' : '1';
		}
	}

	fclose(file);
	return grid;
}



// Saves the grid data to the specified file
void saveGridToFile(char *filename, int rows, int cols, char **grid)
{
	FILE *file = fopen(filename, "w");

	if (file == NULL)
		return;

	// write rows and columns first
	fprintf(file, "%d %d\n", rows, cols);

	// write grid values
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fprintf(file, "%c", grid[i][j]);

			if (j < cols - 1)
				fprintf(file, " ");
		}
		fprintf(file, "\n");
	}

	fclose(file);
}

// Creates and returns a new grid that is a duplicate of the given grid
char **copyGrid(int rows, int cols, char **grid)
{
	char **dup = NULL;

	dup = (char **)malloc(rows * sizeof(char *));
	if (dup == NULL)
		return NULL;

	for (int i = 0; i < rows; i++)
	{
		dup[i] = (char *)malloc(cols * sizeof(char));
		if (dup[i] == NULL)
		{
			for (int k = 0; k < i; k++)
				free(dup[k]);
			free(dup);
			return NULL;
		}

		for (int j = 0; j < cols; j++)
			dup[i][j] = grid[i][j];
	}

	return dup;
}



// Mutates the given grid one generation and return a new grid
char **mutateGrid(int rows, int cols, char **grid)
{
	char **newgrid = copyGrid(rows, cols, grid);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int n = nbrOfNeighbors(i, j, rows, cols, grid);

			if (grid[i][j] == '1')
			{
				if (n < 2 || n > 3)
					newgrid[i][j] = '0';
				else
					newgrid[i][j] = '1';
			}
			else
			{
				if (n == 3)
					newgrid[i][j] = '1';
				else
					newgrid[i][j] = '0';
			}
		}
	}

	return newgrid;
}


// Returns the number of neighbors at postion (i,j) in the grid
int nbrOfNeighbors(int i, int j, int rows, int cols, char **grid)
{
	int neighbors = 0;

	for (int di = -1; di <= 1; di++)
	{
		for (int dj = -1; dj <= 1; dj++)
		{
			if (di == 0 && dj == 0)
				continue;

			int ni = i + di;
			int nj = j + dj;

			if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
			{
				if (grid[ni][nj] == '1')
					neighbors++;
			}
		}
	}

	return neighbors;
}
