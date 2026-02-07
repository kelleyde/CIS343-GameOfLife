//*****************************************************
// Filename: tests.c (unit tests for the game logic)
//
// Author: Jagadeesh Nandigam
//
// IMPORTANT: DO NOT MAKEY ANY CHANGES TO THIS FILE
//***************************************************

#include "CuTest.h"
#include "life.h"

void freeGrid(int rows, int cols, char **grid)
{
    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

void test_loadGridFromFile_1(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("beacon.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  .  . \n .  X  X  .  .  . \n .  X  X  .  .  . \n .  .  .  X  X  . \n .  .  .  X  X  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_loadGridFromFile_2(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("blinker.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  . \n .  .  X  .  . \n .  .  X  .  . \n .  .  X  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_loadGridFromFile_3(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("glider.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  .  .  .  .  . \n .  .  .  .  .  X  .  .  . \n .  .  .  X  .  X  .  .  . \n .  .  .  .  X  X  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_loadGridFromFile_4(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("toad.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  .  . \n .  X  X  X  .  . \n X  X  X  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_loadGridFromFile_5(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("tub.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  . \n .  X  .  .  . \n X  .  X  .  . \n .  X  .  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_saveGridToFile_1(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("beacon.gol", &rows, &cols);
    saveGridToFile("saved.gol", rows, cols, grid);
    freeGrid(rows, cols, grid);
    grid = loadGridFromFile("saved.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  .  . \n .  X  X  .  .  . \n .  X  X  .  .  . \n .  .  .  X  X  . \n .  .  .  X  X  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_saveGridToFile_2(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("blinker.gol", &rows, &cols);
    saveGridToFile("saved.gol", rows, cols, grid);
    freeGrid(rows, cols, grid);
    grid = loadGridFromFile("saved.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  . \n .  .  X  .  . \n .  .  X  .  . \n .  .  X  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_saveGridToFile_3(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("glider.gol", &rows, &cols);
    saveGridToFile("saved.gol", rows, cols, grid);
    freeGrid(rows, cols, grid);
    grid = loadGridFromFile("saved.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  .  .  .  .  . \n .  .  .  .  .  X  .  .  . \n .  .  .  X  .  X  .  .  . \n .  .  .  .  X  X  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_saveGridToFile_4(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("toad.gol", &rows, &cols);
    saveGridToFile("saved.gol", rows, cols, grid);
    freeGrid(rows, cols, grid);
    grid = loadGridFromFile("saved.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  .  . \n .  X  X  X  .  . \n X  X  X  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_saveGridToFile_5(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("tub.gol", &rows, &cols);
    saveGridToFile("saved.gol", rows, cols, grid);
    freeGrid(rows, cols, grid);
    grid = loadGridFromFile("saved.gol", &rows, &cols);
    char *actual = toString(rows, cols, grid);
    char *expected = " .  .  .  .  . \n .  X  .  .  . \n X  .  X  .  . \n .  X  .  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    freeGrid(rows, cols, grid);
    free(actual);
}

void test_copyGrid_1(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("beacon.gol", &rows, &cols);
    char **copy = copyGrid(rows, cols, grid);
    char *str1 = toString(rows, cols, grid);
    char *str2 = toString(rows, cols, copy);
    CuAssertStrEquals(tc, str1, str2);
    CuAssertTrue(tc, grid != copy);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, copy);
    free(str1);
    free(str2);
}

void test_copyGrid_2(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("blinker.gol", &rows, &cols);
    char **copy = copyGrid(rows, cols, grid);
    char *str1 = toString(rows, cols, grid);
    char *str2 = toString(rows, cols, copy);
    CuAssertStrEquals(tc, str1, str2);
    CuAssertTrue(tc, grid != copy);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, copy);
    free(str1);
    free(str2);
}

void test_copyGrid_3(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("glider.gol", &rows, &cols);
    char **copy = copyGrid(rows, cols, grid);
    char *str1 = toString(rows, cols, grid);
    char *str2 = toString(rows, cols, copy);
    CuAssertStrEquals(tc, str1, str2);
    CuAssertTrue(tc, grid != copy);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, copy);
    free(str1);
    free(str2);
}

void test_copyGrid_4(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("toad.gol", &rows, &cols);
    char **copy = copyGrid(rows, cols, grid);
    char *str1 = toString(rows, cols, grid);
    char *str2 = toString(rows, cols, copy);
    CuAssertStrEquals(tc, str1, str2);
    CuAssertTrue(tc, grid != copy);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, copy);
    free(str1);
    free(str2);
}

void test_copyGrid_5(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("tub.gol", &rows, &cols);
    char **copy = copyGrid(rows, cols, grid);
    char *str1 = toString(rows, cols, grid);
    char *str2 = toString(rows, cols, copy);
    CuAssertStrEquals(tc, str1, str2);
    CuAssertTrue(tc, grid != copy);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, copy);
    free(str1);
    free(str2);
}

void test_nbrOfNeighbors(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("blinker.gol", &rows, &cols);
    CuAssertIntEquals(tc, 0, nbrOfNeighbors(0, 0, rows, cols, grid));
    CuAssertIntEquals(tc, 1, nbrOfNeighbors(1, 2, rows, cols, grid));
    CuAssertIntEquals(tc, 2, nbrOfNeighbors(2, 2, rows, cols, grid));
    CuAssertIntEquals(tc, 1, nbrOfNeighbors(3, 2, rows, cols, grid));
    CuAssertIntEquals(tc, 0, nbrOfNeighbors(0, 4, rows, cols, grid));
    CuAssertIntEquals(tc, 0, nbrOfNeighbors(4, 0, rows, cols, grid));
    CuAssertIntEquals(tc, 0, nbrOfNeighbors(4, 4, rows, cols, grid));
    CuAssertIntEquals(tc, 1, nbrOfNeighbors(0, 2, rows, cols, grid));
    CuAssertIntEquals(tc, 0, nbrOfNeighbors(2, 0, rows, cols, grid));
    CuAssertIntEquals(tc, 0, nbrOfNeighbors(2, 4, rows, cols, grid));
    CuAssertIntEquals(tc, 1, nbrOfNeighbors(4, 2, rows, cols, grid));
    freeGrid(rows, cols, grid);
}

void test_mutateGrid_1(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("beacon.gol", &rows, &cols);
    char **mutatedGrid1 = mutateGrid(rows, cols, grid);
    char *actual = toString(rows, cols, mutatedGrid1);
    char *expected = " .  .  .  .  .  . \n .  X  X  .  .  . \n .  X  .  .  .  . \n .  .  .  .  X  . \n .  .  .  X  X  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    char **mutatedGrid2 = mutateGrid(rows, cols, mutatedGrid1);
    actual = toString(rows, cols, mutatedGrid2);
    expected = " .  .  .  .  .  . \n .  X  X  .  .  . \n .  X  X  .  .  . \n .  .  .  X  X  . \n .  .  .  X  X  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, mutatedGrid1);
    freeGrid(rows, cols, mutatedGrid2);
}

void test_mutateGrid_2(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("blinker.gol", &rows, &cols);
    char **mutatedGrid1 = mutateGrid(rows, cols, grid);
    char *actual = toString(rows, cols, mutatedGrid1);
    char *expected = " .  .  .  .  . \n .  .  .  .  . \n .  X  X  X  . \n .  .  .  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    char **mutatedGrid2 = mutateGrid(rows, cols, mutatedGrid1);
    actual = toString(rows, cols, mutatedGrid2);
    expected = " .  .  .  .  . \n .  .  X  .  . \n .  .  X  .  . \n .  .  X  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, mutatedGrid1);
    freeGrid(rows, cols, mutatedGrid2);
}

void test_mutateGrid_3(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("glider.gol", &rows, &cols);
    char **mutatedGrid1 = mutateGrid(rows, cols, grid);
    char *actual = toString(rows, cols, mutatedGrid1);
    char *expected = " .  .  .  .  .  .  .  .  . \n .  .  .  .  X  .  .  .  . \n .  .  .  .  .  X  X  .  . \n .  .  .  .  X  X  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    char **mutatedGrid2 = mutateGrid(rows, cols, mutatedGrid1);
    actual = toString(rows, cols, mutatedGrid2);
    expected = " .  .  .  .  .  .  .  .  . \n .  .  .  .  .  X  .  .  . \n .  .  .  .  .  .  X  .  . \n .  .  .  .  X  X  X  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n .  .  .  .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, mutatedGrid1);
    freeGrid(rows, cols, mutatedGrid2);
}

void test_mutateGrid_4(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("toad.gol", &rows, &cols);
    char **mutatedGrid1 = mutateGrid(rows, cols, grid);
    char *actual = toString(rows, cols, mutatedGrid1);
    char *expected = " .  .  X  .  .  . \n X  .  .  X  .  . \n X  .  .  X  .  . \n .  X  .  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    char **mutatedGrid2 = mutateGrid(rows, cols, mutatedGrid1);
    actual = toString(rows, cols, mutatedGrid2);
    expected = " .  .  .  .  .  . \n .  X  X  X  .  . \n X  X  X  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    char **mutatedGrid3 = mutateGrid(rows, cols, mutatedGrid2);
    actual = toString(rows, cols, mutatedGrid3);
    expected = " .  .  X  .  .  . \n X  .  .  X  .  . \n X  .  .  X  .  . \n .  X  .  .  .  . \n .  .  .  .  .  . \n .  .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, mutatedGrid1);
    freeGrid(rows, cols, mutatedGrid2);
    freeGrid(rows, cols, mutatedGrid3);
}

void test_mutateGrid_5(CuTest *tc)
{
    int rows, cols;
    char **grid = loadGridFromFile("tub.gol", &rows, &cols);
    char **mutatedGrid1 = mutateGrid(rows, cols, grid);
    char *actual = toString(rows, cols, mutatedGrid1);
    char *expected = " .  .  .  .  . \n .  X  .  .  . \n X  .  X  .  . \n .  X  .  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    char **mutatedGrid2 = mutateGrid(rows, cols, mutatedGrid1);
    actual = toString(rows, cols, mutatedGrid2);
    expected = " .  .  .  .  . \n .  X  .  .  . \n X  .  X  .  . \n .  X  .  .  . \n .  .  .  .  . \n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
    freeGrid(rows, cols, grid);
    freeGrid(rows, cols, mutatedGrid1);
    freeGrid(rows, cols, mutatedGrid2);
}

CuSuite *StrUtilGetSuite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_loadGridFromFile_1);
    SUITE_ADD_TEST(suite, test_loadGridFromFile_2);
    SUITE_ADD_TEST(suite, test_loadGridFromFile_3);
    SUITE_ADD_TEST(suite, test_loadGridFromFile_4);
    SUITE_ADD_TEST(suite, test_loadGridFromFile_5);
    SUITE_ADD_TEST(suite, test_saveGridToFile_1);
    SUITE_ADD_TEST(suite, test_saveGridToFile_2);
    SUITE_ADD_TEST(suite, test_saveGridToFile_3);
    SUITE_ADD_TEST(suite, test_saveGridToFile_4);
    SUITE_ADD_TEST(suite, test_saveGridToFile_5);
    SUITE_ADD_TEST(suite, test_copyGrid_1);
    SUITE_ADD_TEST(suite, test_copyGrid_2);
    SUITE_ADD_TEST(suite, test_copyGrid_3);
    SUITE_ADD_TEST(suite, test_copyGrid_4);
    SUITE_ADD_TEST(suite, test_copyGrid_5);
    SUITE_ADD_TEST(suite, test_nbrOfNeighbors);
    SUITE_ADD_TEST(suite, test_mutateGrid_1);
    SUITE_ADD_TEST(suite, test_mutateGrid_2);
    SUITE_ADD_TEST(suite, test_mutateGrid_3);
    SUITE_ADD_TEST(suite, test_mutateGrid_4);
    SUITE_ADD_TEST(suite, test_mutateGrid_5);
    return suite;
}

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, StrUtilGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void)
{
    RunAllTests();
}
