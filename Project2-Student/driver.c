//***************************************************
// Filename: driver.c
//
// Author: Jagadeesh Nandigam
//
// IMPORTANT: DO NOT MAKEY ANY CHANGES TO THIS FILE
//***************************************************

#include "life.h"

void freeGrid(int rows, int cols, char **grid)
{
	for (int i = 0; i < rows; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

int main(int argc, char **argv)
{
	// check if a filename is given as commmand line argument
	if (argc != 2)
	{
		printf("This program requires a filename as argument.\n");
		printf("Correct usage: ./driver filename\n");
		printf("Example: ./driver blinker.gol\n");
		exit(EXIT_FAILURE);
	}

	int rows, cols;
	char **grid, **mutatedGrid, *gridString, filename[25];

	// create grid from data read the file
	grid = loadGridFromFile(argv[1], &rows, &cols);

	// get a string representation of the grid
	gridString = toString(rows, cols, grid);

	// display the grid and free the storage allocated for the string variable
	printf("<<<<< Welcome to the Game of Life >>>>>\n");
	printf("\n%s\n", gridString);
	free(gridString);

	// play the game
	while (true)
	{
		printf("Press n (or return) for next generation, i to iterate, l to load grid, s to save grid, or q to quit >> ");
		char input[3];
		fgets(input, 3, stdin);

		switch (input[0])
		{
		case 'q':
			// free memory allocated for the grid and exit the game
			freeGrid(rows, cols, grid);
			return EXIT_SUCCESS;

		case 'l':
			printf("Enter filename to load the grid: ");
			fgets(filename, 25, stdin);
			// replace newline character with string terminator character
			filename[strlen(filename) - 1] = '\0';
			grid = loadGridFromFile(filename, &rows, &cols);
			gridString = toString(rows, cols, grid);
			printf("\n%s\n", gridString);
			free(gridString);
			break;

		case 's':
			printf("Enter filename to save the grid: ");
			fgets(filename, 25, stdin);
			// replace newline character with string terminator character
			filename[strlen(filename) - 1] = '\0';
			saveGridToFile(filename, rows, cols, grid);
			printf("Grid saved to file %s\n\n", filename);
			break;

		case 'i':
			printf("Enter number of iterations: ");
			char buf[5];
			fgets(buf, 5, stdin);
			// replace newline character with string terminator character
			buf[strlen(buf) - 1] = '\0';
			int num = atoi(buf);

			for (int i = 0; i < num; ++i)
			{
				mutatedGrid = mutateGrid(rows, cols, grid);
				gridString = toString(rows, cols, mutatedGrid);
				printf("\n%s\n", gridString);
				free(gridString);
				freeGrid(rows, cols, grid);
				grid = mutatedGrid;
			}
			break;

		case 'n':
		default:
			mutatedGrid = mutateGrid(rows, cols, grid);
			gridString = toString(rows, cols, mutatedGrid);
			printf("\n%s\n", gridString);
			free(gridString);
			freeGrid(rows, cols, grid);
			grid = mutatedGrid;
		}
	}
}
