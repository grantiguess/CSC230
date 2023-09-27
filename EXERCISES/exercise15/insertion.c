// Code to read numbers from standard input inserting them into a list
// in sorted order as we read them.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for building our linked list.
struct NodeStruct {
  // Value in this node.
  int value;

  // Pointer to the next node.
  struct NodeStruct *next;
};

// A short type name to use for a node.
typedef struct NodeStruct Node;

/*
  Create a node for the given value and insert it into the given list
  in the proper location to keep the list sorted.  Return an updated
  head pointer.  The head should only need to change if this value gets
  inserted at the front of the list.  Otherwise, you can just return
  the old head pointer.
*/
Node *insert( Node *head, int val )
{
    //dynamically allocate and init. node from params
    Node *n = (Node *)malloc( sizeof( Node ) );
    n->value = val;

    //if list is empty, add to front
    if ( head == NULL ) {
        head = n;
        return head;
    }
    //if he new value is the smallest, add to front and put everything else after
    if ( val < head->value ) {
        n->next = head;
        head = n;
        return head;
    }

    Node *prev = head;
    Node *idx = head;
    for ( idx = head; idx; idx = idx->next ) {
        if ( idx->next == NULL ) { //if there is nothing next, add to the end
            if ( val > idx->value ) {
                idx->next = n;
                return head;
            }
            else {
                n->next = idx; //link idx after n
                prev->next = n; //link n after prev
                return head;
            }

            idx->next = n;
            return head;
        }
        else if ( val < idx->value ) { //if spot is found
            //link the list like this: ... -> prev -> n -> idx -> ...
            n->next = idx; //link idx after n
            prev->next = n; //link n after prev
            return head;
        }
        prev = idx;
    }

    //this code only executes if the loop ends, so
    //add to the end if the value has not been added yet
    idx->next = n;

    //TODO: check if freeing prev here breaks the list
  return head;
}

int main()
{
  // Pointer to the head node.
  Node *head = NULL;

  // Read a list of numbers from building a sorted list as we
  // read them.
  int x;
  while ( scanf( "%d", &x ) == 1 ){
    // Insert the new value, and get back the (possibly updated) head pointer.
    head = insert( head, x );
  }

  // Print out the list.
    for ( Node *n = head; n; n = n->next ) {
        printf( "%d ", n->value );
    }
    printf( "\n" );
  
  // Free all the nodes.
  while ( head ) {
    Node *next = head->next;
    free( head );
    head = next;
  }
  
  return 0;
}
