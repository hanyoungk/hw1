/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include<iostream>

using namespace std;


int main(int argc, char* argv[])
{
    Node * test = new Node(1,nullptr);
    test->next = new Node(1,nullptr);
    test->next->next = new Node(2,nullptr);
    test->next->next->next = new Node(4,nullptr);
    test->next->next->next->next = new Node(5,nullptr); 

    Node * odds = nullptr;
    Node * evens = nullptr;
 
    split(test, odds, evens);

    Node * temp = odds;
    cout << "odds list: ";
    while(temp)
    {
        cout << temp->value << ",";
        temp = temp->next;
    }
    cout << endl;

    temp = evens;
    cout << "evens list: ";
    while(temp)
    {
        cout << temp->value << ",";
        temp = temp->next;
    }
    cout << endl;

    temp = test;
    cout << "in list: ";
    while(temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }


    //cleaning up...
    while(evens)
    {
        Node * temp = evens->next;
        delete evens;
        evens = temp;
    }
    while(odds)
    {
        Node * temp = odds->next;
        delete odds;
        odds = temp;
    }
    cout << endl;

    // Node* head = nullptr;

    // head->next = addtolist(head, 1);
    // head->next = addtolist(head, 2);
    // head->next = addtolist(head, 3);
    // head->next = addtolist(head, 5);

    // Node* odds = nullptr;
    // Node* evens = nullptr;
    
    // split(head, odds, evens);

    
}
