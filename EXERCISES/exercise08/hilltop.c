#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readGrid( int rows, int cols, int grid[ rows ][ cols ] )
{
    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < cols; j++ ) {
            int val = 0;
            scanf( "%d", &val );
            grid[ i ][ j ] = val;
        }
    }
    
}

// Add parameters to to pass a variable-sized array to the following
// function.  It's the same as the previous function, but I want you
// to get a chance to type it in yourself.
void reportMaxima( int rows, int cols, int grid[ rows ][ cols ] )
{
    //check each bucket in array to see if value is greater than all neighbors' values
    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < cols; j++ ) {
            bool maxima = true;

            //this is the ugliest edge detection ever written but it is okay! (and it's O(n) !!!)
            if ( i > 0 ) { //check to see if you're at the top
                //check top neighbor
                if ( grid[ i ][ j ] < grid[ i - 1 ][ j ] ) {
                    maxima = false;
                }
                if ( j > 0 ) {
                    //check top-left neighbor
                    if ( grid[ i ][ j ] < grid[ i - 1 ][ j - 1 ] ) {
                        maxima = false;
                    }
                }
                if ( j < cols - 1 ) {
                    //check top-right neighbor
                    if ( grid[ i ][ j ] < grid[ i - 1 ][ j + 1 ] ) {
                        maxima = false;
                    }
                }
            }

            if ( i < rows - 1 ) { //check to see if you're at the bottom
                //check bottom neighbor
                if ( grid[ i ][ j ] < grid[ i + 1 ][ j ] ) {
                    maxima = false;
                }
                if ( j < cols - 1 ) {
                    //check bottom-right neighbor
                    if ( grid[ i ][ j ] < grid[ i + 1 ][ j + 1 ] ) {
                        maxima = false;
                    }
                }
                if ( j > 0 ) {
                    //check bottom-left neighbor
                    if ( grid[ i ][ j ] < grid[ i + 1 ][ j - 1 ] ) {
                        maxima = false;
                    }
                }
            }

            if ( j > 0 ) { //check to see if you're at the left
                //check left neighbor
                if ( grid[ i ][ j ] < grid[ i ][ j - 1 ] ) {
                    maxima = false;
                }
            }

            if ( j < cols - 1 ) { //check to see if you're at the right
                //check right neighbor
                if ( grid[ i ][ j ] < grid[ i ][ j + 1 ] ) {
                    maxima = false;
                }
            }

            if ( maxima ) {
                printf( "%d %d\n", i, j );
            }
        }
    }
}

int main()
{
  // Add code to read in the grid size from standard input.
    int rows = 0;
    int cols = 0;
    scanf( "%d%d", &rows, &cols );

  // Declare a variable-sized array to hold the grid.
    int grid[ rows ][ cols ];

  // Call readGrid() to populate the array.
    readGrid( rows, cols, grid );
  
  // Call reportMaxima() to print out all local maxima.
    reportMaxima( rows, cols, grid );
  
  return EXIT_SUCCESS;
}
