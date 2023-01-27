#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& value)
{
  // if empty, create new item
  if(empty())
  {
    Item* node = new Item();
    head_ = node;
    tail_ = node;

    tail_->first = 0;
    tail_->last = 0;

    tail_->val[0] = value;
    tail_->last++;
    size_++;
  }
  //if the last node is full
  else if(tail_->last == ARRSIZE)
  {
    Item* node2 = new Item();

    tail_->next = node2; //set the current tail's next as node2
    node2->prev = tail_; //set node2's prev as current tail

    tail_ = node2; //set node2 as the new tail
    tail_->first = 0;
    tail_->last = 1;

    tail_->val[tail_->first] = value;
    size_++;
  }
  else
  {
    tail_->val[tail_->last] = value; //assign value to index
    tail_->last++; //increment last index
    size_++; //increment size
  }
}

void ULListStr::pop_back()
{
  //if tail node's array is only one index filled
  if(empty())
  {
    return;
  }
  else if(tail_->last == 1) //theres one index filled
  {

    if(tail_->prev == NULL) //if there is only one item 
    {
      //set the head and tail to null
      // head_ = NULL; 
      delete tail_; //error
      tail_ = NULL;

      head_ = NULL;

      size_--; //decrement size
    }
    else //theres more than 1 item
    {
      // Item* temp = new Item();
      Item* temp = tail_;

      tail_ = tail_->prev; //set the tail to tail's previous item
      delete temp; //delete the temp that stores the old tail
      tail_->next = NULL; //set the previous' node's next to null

      size_--; //decrement size
    }
    // size_--; //decrement size
  }
  else //for all other cases
  {
    tail_->last--; //moves the tail pointer to the previous index
    size_--; //decrement size
  } 
}

void ULListStr::push_front(const std::string& value)
{
  //if empty, create new item
  if(empty())
  {
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    // size_ = 0;

    head_->first = ARRSIZE;
    head_->last = ARRSIZE;

    head_->val[9] = value;
    head_->first--;
    size_++;
  }

  //if the array in the item is full
  else if(head_->first == 0)
  {
    Item* node2 = new Item();

    head_->prev = node2; //set the current head's prev as node2
    node2->next = head_; //set node2's next as current head

    head_ = node2; //set node2 as the new head
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;

    head_->val[head_->first] = value;
    size_++;
  }
  else
  {
    head_->val[head_->first - 1] = value;
    head_->first--;
    size_++;
  }

  // head_->val[ARRSIZE - head_->first] = value;
  // head_->first--;
  // size_++;

}


//add a if condition to see if it is the only item
void ULListStr::pop_front()
{
  if(empty())
  {
    return;
  }
  //else if head node's array is not filled all the way
  else if(head_->last - head_->first > 1)
  {
    head_->first++; //moves the tail pointer to the previous index
    size_--;
  } 
  else //if there is only one index filled
  {
    if(head_->next == NULL) //if there is only one item/node
    {
      tail_ = NULL;
      delete head_;
      head_ = NULL;
    }
    else
    {
      // Item* temp = new Item();

      Item* temp = head_;

      head_ = head_->next; //set the head to head's previous item
      delete temp;
      head_->prev = NULL; //set the previous' node's prev to null
    }
    size_--;
  }

}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];

}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // Item* temp = new Item();

  // temp = head_;

  
  if(loc < 0 || loc > size()) //if loc is out of bound/not valid
  {
    return NULL;
  }
  Item* temp = head_;

  while(temp->next != NULL)
  {
    if((temp->last - temp->first - 1 ) < loc) //if loc is bigger than size of list
    {
      loc -= temp->last - temp->first; //subtract list size from loc
      temp = temp->next; //move on to the next list
    }
    else 
      break;
  }

  

  

  return &temp->val[temp->first + loc];
}
