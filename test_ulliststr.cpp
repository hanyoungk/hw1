#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

    //1.1 empty list
    cout << "test case 1:" << endl;
    ULListStr test1; 

    cout << "empty list? " << boolalpha << test1.empty() << endl;


    //test popping for empty list
    test1.pop_back();
    test1.pop_front();
    cout << "after popping back in empty list: ";
    for(size_t i = 0; i < test1.size(); i++)
    {
        cout << test1.get(i) << " ";
    }
    cout << endl;

    //test pushing for empty list
    test1.push_back("back");
    test1.push_front("front");
    test1.push_front("front");

        //cout test1 linked list
    cout << "after push back: " ;
    for(size_t i = 0; i < test1.size(); i++)
    {
        cout << test1.get(i) << " ";
    }
    cout << endl;
    cout << "size of new list: " << test1.size() << endl;

    test1.pop_back();
    test1.pop_front();
        //cout test1 linked list
    
    cout << "after popping back&front: ";
    for(size_t i = 0; i < test1.size(); i++)
    {
        cout << test1.get(i) << " ";
    }
    cout << endl;

    //2.1 1 item with index not filled all the way
    cout << "\ntest case 2:" << endl;

    ULListStr test2;

    test2.push_back("a");

    test2.push_back("b");
    test2.push_back("c");
    test2.push_back("d");
    test2.push_back("e");
    test2.push_back("f");
    test2.push_back("g");
    test2.push_back("h");

    cout << "test 2 list: ";
    for(size_t i = 0; i < test2.size(); i++)
    {
        cout << test2.get(i) << " ";
    }
    cout << endl;

    test2.pop_back(); //h is deleted
    cout << "after deleting h: ";
    for(size_t i = 0; i < test2.size(); i++)
    {
        cout << test2.get(i) << " ";
    }
    cout << endl;

    test2.push_back("h");
    test2.push_back("i");
    test2.push_back("j");
    test2.push_back("new1");
    test2.push_back("new2");
    test2.push_back("new3");

    cout << "h,i,j,new1-3 added: ";
    for(size_t i = 0; i < test2.size(); i++)
    {
        cout << test2.get(i) << " ";
    }
    cout << endl;
    cout << "size of new list: " << test2.size() << endl;

    cout << "\npopping back until 1 \"item\" left" << endl;
    test2.pop_back();
    test2.pop_back();
    test2.pop_front();
    for(size_t i = 0; i < test2.size(); i++)
    {
        cout << test2.get(i) << " ";
    }
    cout << endl;
    cout << "size of new list: " << test2.size() << endl;

    test2.set(test2.size() - 1, "set_back");
    test2.set(0, "set_front");


    cout << "\nset front and back diff val." << endl;
    cout << "front: " << test2.front() << endl;
    cout << "back: " << test2.back() << endl;

    cout << "new test2 list: ";
    for(size_t i = 0; i < test2.size(); i++)
    {
        cout << test2.get(i) << " ";
    }
    cout << endl;
    

    cout << "\ntesting clear() function: ";
    test2.clear();
    for(size_t i = 0; i < test2.size(); i++)
    {
        cout << test2.get(i) << " ";
    }
    cout << endl;
    cout << "empty list? " << boolalpha << test2.empty() << endl;



    //3.1 multiple items with index not filled all the way

    ULListStr test3;

    for(size_t i = 0; i < 14; i++)
    {
        test3.push_front(to_string(i));
        test3.push_back(to_string(i));
    }

    cout << "test3 list: ";
    for(size_t i = 0; i < test3.size(); i++)
    {
        cout << test3.get(i) << " ";
    }
    cout << endl;

    for(size_t i = 0; i < 7; i++)
    {
        test3.pop_front();
        test3.pop_back();
    }

    cout << "new test3 list: ";
    for(size_t i = 0; i < test3.size(); i++)
    {
        cout << test3.get(i) << " ";
    }
    cout << endl;

    


    //3.2 mult items with 1 index filled


    //3.3 mult items with all index filled




}
