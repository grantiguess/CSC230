#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  // For NULL, although we don't need it.

void incrementAll( int* a, int* b, int* c, int d )
{
    *a += d;
    *b += d;
    *c += d;
}

void rotate( int* a, int* b, int* c )
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int* getLargest( int* a, int* b, int* c  )
{
    if ( *a > *b && *a > *c ) {
        return a;
    }
    if ( *b > *a && *b > *c ) {
        return b;
    }
    else return c;
}

int main()
{
  int a = 100;
  int b = 50;
  int c = 25;

  // Get initial values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  // Call a function to increment all the values by the given constant
  // (10 here)
  incrementAll( &a, &b, &c, 10 );

  // Report current values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  // Simultaneously move the value from b to a, from c to b and from a
  // to c.
  rotate( &a, &b, &c );

  // Report current values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  // Get back a pointer to the largest value.
  int *largest = getLargest( &a, &b, &c );

  // Make this value smaller.  We do need the parentheses here.
  (*largest)--;

  // Report final values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  return EXIT_SUCCESS;
}
