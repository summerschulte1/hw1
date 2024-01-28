#include <cstddef>
#include <stdexcept>
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
std::string const & ULListStr::front() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head_->val[head_->first];
}
std::string const & ULListStr::back() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    // Since 'last' is exclusive, we subtract 1 to get the index of the last element
    return tail_->val[tail_->last - 1];
}

void ULListStr::push_back(const std::string& val){
  //check if tail has room in array OR if list is empty
  if (tail_ == NULL) {
    //allocate new item 
    Item* newItem = new Item();
    newItem->val[0] = val; //put it at front of array
    head_ = tail_ = newItem; //make head and tail this new item 
    newItem->last = 1;
  }
  else if (tail_->last < ARRSIZE) { //theres room at end 
    tail_->val[tail_->last++] = val;
    //size_++;
  }
 // else if (tail_->last == ARRSIZE && tail_->first == 0) {
 //   //no room in list, allocate new item 
 //   Item* newItem = new Item();
 //   newItem->val[newItem->last++] = val;
  //  tail_->next = newItem;
  //  newItem->prev = tail_;
  //  tail_ = newItem;
  //  size_++;
//  } 
else {
    Item* newItem = new Item();
    newItem->val[newItem->last++] = val;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
  }
  size_++;

}

void ULListStr::pop_back(){
  //check if list is empty
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  
  
  tail_->last--;
  size_--;

  //check is the node is empty now
  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    //check for previous node
    if (tail_) {
     // tail_ = tail_->prev;
      tail_->next = NULL;

    }
    //there was only one node
    else {
      head_ = NULL; 
    }
    delete temp; //deallocate
  }
}
void ULListStr::push_front(const std::string& val){
  //check if array has room 
  //if first == 0, then that means theres no room
  if (head_ == NULL || head_->first == 0) {
    //if this is triggered, we need to allocate a new node 
    Item* newItem = new Item();

    //in the case that head_->first == 0 (its full)
    if (head_!= NULL) {
      head_->prev = newItem;
      newItem->next = head_; //pointing to each other 

    }
    else {
      tail_ = newItem;
    }
    newItem->prev = NULL;
    newItem->val[ARRSIZE - 1] = val;
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
    head_ = newItem;
//check if this is the first item in list 
    
  }
  //if there is room in array 
  else {
    head_->val[--head_->first] = val;

  }
  size_++;

}
void ULListStr::pop_front() {
  //check if list is empty
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  head_->first++;
  size_--;
  //check if this is the only item in the array ->deallocate 
  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;

    //now check if there is a next node 
    if (head_) {
      head_->prev = NULL;

    }
    else { //the list will be completely empty 
      tail_ = NULL;

    }
    delete temp; //deallocate 
  }
}
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return nullptr;
  }

  Item* current = head_;
  while (current != nullptr) {
    size_t numElementsInNode = current->last - current->first;
    if (loc < numElementsInNode) {
      return &current->val[current->first + loc];
    }
    loc -= numElementsInNode;
    current = current->next;
  }
  return nullptr;
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
