// Same job as the gcd.c program, but this one does everything without
// a separate GCD function and without any structured looping
// constructs (so, it's kind of ugly compared to the original program).

#include <stdio.h>
#include <stdlib.h>

/*
  Report the GCD for a sequence of user queries.
 */
int main( void )
{
  // Pair of values we're supposed to report GCD for.
  int a, b;

    input:
    if ( scanf( "%d%d", &a, &b ) == 2 && ( a != 0 || b != 0 ) ) {
        // Compute the GCD and print it.
        goto loopStart;
        print:
        printf( "%d\n", a );
        goto input;
    }
    else {
        return EXIT_SUCCESS;
    }
    

  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;

  // Write your own, ugly solution, using goto instead of structured looping.
    int temp;
    loopStart:
    temp = a;
    a = b;
    b = temp % b;
    if (b != 0) {
        goto loopStart;
    }
    else {
        goto print;
    }

  return EXIT_SUCCESS;
}
