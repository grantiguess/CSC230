#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Maximum length for strings in this exercise (not counting the null
    terminator). */
#define STRING_LIMIT 80

/** Report that the input is invalid and exit unsuccessfully. */
static void invalid()
{
  fprintf( stderr, "Invalid input\n" );
  exit( EXIT_FAILURE );
}

int main()
{
  // Read the filename from standard input.
  char filename[ STRING_LIMIT + 1 ];
  scanf( "%s", filename );

  // Open an input file with the given name.
  FILE *stream = fopen( filename, "r" );

  // This is the representation of the string we're creating.  It starts out
  // as an empty string.
  char str[ STRING_LIMIT + 1 ] = "";

  // Current length of the string.  We could use strlen(), but it's convenient
  // to aslo have a variable for this.
  int len = 0;

  // Read the word at the start of each command.
  char cmd[ STRING_LIMIT + 1 ] = "";
  while ( fscanf( stream, " %s", cmd ) == 1 ) {
    // Read the operands for the operation.  Make sure it's valid and
    // modify the string if it is.
    int idx = 0;
    fscanf( stream, "%d", &idx );

    if ( strcmp( cmd, "insert" ) == 0 ) {
        len++;
        char ch;
        fscanf( stream, " %c", &ch );

        if ( ch < 0x21 || ch > 0x7E || len >= 80 ) {
            invalid();
        }

        for ( int i = len; i > idx; i-- ) {
            str[i] = str[i - 1];
        }
        str[idx] = ch;
        str[len] = '\0';
    }
     
    else if ( strcmp( cmd, "delete" ) == 0 ) {
        if ( len == 0 ) {
            invalid();
        }
        for ( int i = idx; i < len; i++ ) {
            str[i] = str[i + 1];
        }
        len--;
        str[len] = '\0';
    }
    else invalid();
    
    // Print out the current state of the string.
    printf( "%s\n", str );
  }

  // Close the input file.
  fclose( stream );

  return EXIT_SUCCESS;
}
