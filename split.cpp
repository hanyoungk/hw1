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

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  if(in != nullptr)
  {
    split(in->next, odds, evens); //get to null/tail pointer

    if((in->value)%2) //if the value is odd
    {
      in->next = odds;
      odds = in;
      in = nullptr;


    }
    else if (!((in->value)%2)) //if the value is even
    {
      in->next = evens;
      evens = in;
      in = nullptr;
    }
  }
  else if(in == nullptr) //when in is null, recurse back to do calculation
  {
    if(odds != nullptr)
      odds = nullptr;
    if(evens != nullptr)
      evens = nullptr;
    
    return;
  }

  // if(in == nullptr) // in pointer reached NULL
  // {
  //   if(odds != nullptr)
  //     odds = nullptr;
  //   if(evens != nullptr)
  //     evens = nullptr;
    
  //   return;
  // }
  // else
  // {
  //   split(in->next, odds, evens); //get to null/tail pointer

  //   if((in->value)%2 != 0) //if the alue is odd
  //   {
  //     in->next = odds;
  //     odds = in;
  //     in = nullptr;


  //   }
  //   else if ((in->value)%2 == 0)
  //   {
  //     in->next = evens;
  //     evens = in;
  //     in = nullptr;
  //   }

  // }





//   else if((in->value)%2 == 0) //if the value is even
//   {
//     // split(in->next, odds, evens);
//     evens = in;
//     Node* tempNext = in->next;
//     in->next = nullptr;
//     // in = evens->next;
//     // evens->next = nullptr; //set the next node of evens as null

//     //go to the next value in the in's linked list
//     // in = in->next; //set the next node as the next's next

//     split(tempNext, odds, evens->next); //recursive call 
//     // in = nullptr;
//   }
//   else if((in->value)%2 != 0)
//   {
//     odds = in;
//     Node* tempNext = in->next;
//     in->next = nullptr;
//     // in = odds->next;
//     // odds->next = nullptr;

//     // in = in->next;

//     split(tempNext, odds->next, evens); //recursive call
//     // in = nullptr;
//   }




}
// /* If you needed a helper function, write it here */ 