/** 
  @file gcd.c 
  This program reads pairs of numbers from the user and reports the
  greatest common divisor of eacn pair.
*/

#include <stdio.h>
#include <stdlib.h>

/** 
    Given two integers, computes their greatest common divisor.  The
    two arguments should not both be zeros.
    @param a the first integer.
    @param b the second integer.
    @return the gcd of a and b.
*/
int GCD( int a, int b )
{
  // Convert to positive a and b (GCD makes sense for positive or
  // negative values, but the loop below expects non-negative values)
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  
  // As long as b is non-zero, we can simplify the problem by computing
  // the GCD of b and a % b
  while ( b != 0 ){
    int temp = a;
    a = b;
    b = temp % b;
  }
  
  return a;
}

/*
  Report the GCD for a sequence of user queries.
*/
int main()
{
  // Pair of values we're supposed to report GCD for.
  int a, b;

  // Keep reading pairs of input values until we get two zero values.
  while ( scanf( "%d%d", &a, &b ) == 2 && ( a != 0 || b != 0 )) {

    // Compute the GCD and print it.
    int c = GCD( a, b );
    printf( "%d\n", c );
    
  }

  return EXIT_SUCCESS;
}
