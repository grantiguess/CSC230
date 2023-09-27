/**
  @file chessboard.c
  This program decodes a chessboard description in a compressed representation
  and draws a picture of the chessboard as output.
*/

#include <stdio.h>
#include <wchar.h> // For wide characters.
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/** Maximum number of command-line arguments. */
#define MAX_ARGS 2

/** Width and height of the chessboard. */
#define SIZE 8

/** Piece type value for a pawn. */
#define PAWN 1

/** Piece type value for a knight (shown as N) */
#define NGHT 2

/** Piece type value for a bishop */
#define BSHP 3

/** Piece type value for a rook */
#define ROOK 4

/** Piece type value for a queen */
#define QUEN 5

/** Piece type value for a king */
#define KING 6


/** Representation of a chess piece on the 2D board. */
typedef struct {
  /** True if this is a light-side piece. */
  bool light;
  
  /** Type of the piece, or zero for empty. */
  int type;
} Piece;

/**
  Initiates a blank chessboard.
  @param board Array representing a chessboard.
*/
void initBoard( Piece board[SIZE][SIZE] )
{
  for ( int i = 0; i < SIZE; i++ )
    for ( int j = 0; j < SIZE; j++ )
      board[ i ][ j ] = (Piece) { false, 0 };
}

/**
   Decode a piece from the given input value and fill in the appropriate board
   position.
   @param input Encoding of the piece type and location.
   @param board Representation of the chessboard.
*/
void decodeInput( unsigned short input, Piece board[SIZE][SIZE] )
{
    /* DEFINE THE MASKS AND SHIFTS */
    unsigned short colMask = 0x7; //7 or 0000000000000111
    unsigned short colShift = 0;

    unsigned short rowMask = 0x38; //56 or 0000000000111000
    unsigned short rowShift = 3;

    unsigned short typeMask = 0x1C0; //448 or 000000111000000
    unsigned short typeShift = 6;

    unsigned short lightMask = 0x200; //512 or 0000001000000000
    unsigned short lightShift = 9;
    /*------------------------------------------------*/

    unsigned short row = 0;
    unsigned short col = 0;
    unsigned short type = 0;
    bool light = 0;

    col = ( ( input & colMask ) >> colShift );
    row = ( ( input & rowMask ) >> rowShift );
    type = ( ( input & typeMask ) >> typeShift );
    light = ( ( input & lightMask ) >> lightShift );

    //printf( "input: %d, col: %d, row: %d, type: %d, light: %d\n", input, col, row, type, light );

    board[ row ][ col ].light = light;
    board[ row ][ col ].type = type;
}

/**
  Print the chessboard as ASCII text format. 
  @param board Representation of the chessboard.
*/
void printBoardText( Piece board[SIZE][SIZE] )
{
    for ( int i = 0; i < SIZE; i++ ) { //row
        for ( int j = 0; j < SIZE; j++ ) { //col
            unsigned short p = board[i][j].type;
            bool light = board[i][j].light;
            switch ( p ) 
            {
            case 0:
                printf( "-" );
                break;
            case PAWN:
                if ( light ) {
                    printf( "P" );
                }
                else printf( "p" );
                break;
            case NGHT:
                if ( light ) {
                    printf( "N" );
                }
                else printf( "n" );
                break;
            case BSHP:
                if ( light ) {
                    printf( "B" );
                }
                else printf( "b" );
                break;
            case ROOK:
                if ( light ) {
                    printf( "R" );
                }
                else printf( "r" );
                break;
            case QUEN:
                if ( light ) {
                    printf( "Q" );
                }
                else printf( "q" );
                break;
            case KING:
                if ( light ) {
                    printf( "K" );
                }
                else printf( "k" );
                break;
            default:
                break;
            }

            if ( j < SIZE - 1 ) {
                printf( " " );
            }
        }
        if ( i < SIZE ) {
            printf( "\n" );
        }
    }
    //printf( "\n" );
}

/**
   This funciton is just for fun.  It prints the chessboard using unicode
   characters for the chess pieces, rather than letters.  This function has to do
   some things you shouldn't do if you just have to print the board as ACII text.
   @param board Representation of the chessboard.
*/
void printBoardGraphical( Piece board[SIZE][SIZE])
{
  // Wide character code used to print each type of piece.
  static const int symbols[][ 2 ] = { { '-', '-' }, // empty
                                      { 0x2659, 0x265F }, // pawn
                                      { 0x2658, 0x265E }, // knight
                                      { 0x2657, 0x265D }, // bishop
                                      { 0x2656, 0x265C }, // rook
                                      { 0x2655, 0x265B }, // queen
                                      { 0x2654, 0x265A } }; // king
  
  setlocale(LC_CTYPE, "");
  for (int r = 0; r < SIZE; r++) {
    for (int c = 0; c < SIZE; c++) {
      // Blanks bttween the pieces.
      if ( c > 0 )
        wprintf( L" " );
      wprintf( L"%lc", symbols[ board[r][c].type ][ board[r][c].light ] );
    }
    wprintf(L"\n");
  }
}

int main(int argc, char *argv[])
{
  // Make an empty chessboard.
  Piece chessboard[SIZE][SIZE];
  initBoard( chessboard );
  
  // Poitner to the function we'll use for printing the board.
  void (*boardPrinter)( Piece board[SIZE][SIZE] ) = printBoardText;

  // Swap out the board printer if the user asks for it.
  if ( argc == MAX_ARGS && strcmp(argv[ 1 ], "-u" ) == 0 )
    boardPrinter = printBoardGraphical;
  

  // Read a sequence of hexadecimal values from standard input, decode them
  // and update the chessboard.
    unsigned short input;
    while ( fscanf( stdin, "%hx", &input ) == 1 ) {
        decodeInput( input, chessboard );
    }

  // Print the board, using the current board printer function.
  boardPrinter( chessboard );
  
  return EXIT_SUCCESS;
}
