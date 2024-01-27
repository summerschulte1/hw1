/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void addtolist(Node*& list, Node* newnode) {
  if (list == NULL) {
    list = newnode;
  }
  else {
    addtolist(list->next,newnode);
  }
}

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

//when the funciton terminates, in shouls be set to NULL 
///in is the original list (i think)
//odds should point to the head of the odds list 
//evens should point to the head of the even list


//recursion!
//base case (if any of the lists are null)
if (in == NULL) {
  return;
}
//storing "next item" so that we can terminate 'in'
Node* nextnode = in->next;
if (in->value % 2 == 0) { //its even
in->next = NULL; //does it never terminate the first item?
addtolist(evens,in);
  
}
else {
  in->next = NULL;
  addtolist(odds,in);
}

in = nextnode;
split(in,odds,evens);



}

/* If you needed a helper function, write it here */
