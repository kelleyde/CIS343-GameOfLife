//***************************************************
// Filename: life.h
//
// Author: Jagadeesh Nandigam
//
// IMPORTANT: DO NOT MAKEY ANY CHANGES TO THIS FILE
//***************************************************

#ifndef LIFE_H_

#define LIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Constructs and returns a string representation of the grid (mostly for display/testing purposes)
char *toString(int rows, int cols, char **grid);

// Creates a grid of rows x cols and initializes the grid with data from specified file
char **loadGridFromFile(char *filename, int *rows, int *cols);

// Saves the grid data to the specified file
void saveGridToFile(char *filename, int rows, int cols, char **grid);

// Creates and returns a new grid that is a duplicate of the given grid
char **copyGrid(int rows, int cols, char **grid);

// Mutates the given grid one generation and return a new grid
char **mutateGrid(int rows, int cols, char **grid);

// Returns the number of neighbors at postion (i,j) in the grid
int nbrOfNeighbors(int i, int j, int rows, int cols, char **grid);

#endif /* LIFE_H_ */
