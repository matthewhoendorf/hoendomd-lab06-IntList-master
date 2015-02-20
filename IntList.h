#ifndef IntLIST_H
#define IntLIST_H 

/**   @file IntList.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu
      @date 10-04-14
      @version 0.01   
      
      This IntList class represents a singly linked-list storing integers.
      
      Various class members need to be implemented.
      
**/
#include <iostream>

using namespace std;

class IntList{

  public:
  IntList();
  ~IntList();
  
  void push_front(int value); // Puts value at the beginning of the list.
  void push_back(int value);  // Puts value at the end of the list
  
  bool setAt(int value, int location);// Returns false if not possible
              // Negative values are from the end. -1 is last
              // location is 0 based.
  
  int getAt(int location) const;// Returns 0 if location not valid.  negative OK
              // Returns the value at that location if valid.
  
  bool insert(int value, int location); // Puts value BEFORE location in
              // in the linked list.  false if invalid location.  
              // A location of size should put the value at the end of the list,
              // as will location -1.  (Negs are AFTER location)
              
  bool remove(int location); // Removes the element at location, making the
              // linked-list smaller by 1.  Negatives OK
  
  string print() const; // Resturns the linked-list to cout in some 
              // understandable way as a string.
  
  unsigned int size() const; // Returns the number of elements in the linked-list
  
  private:  // You can change anything you'd like below
  
  class Node{
    public:
    Node(){value=0;next=NULL;};
    ~Node(){delete next;};
    int value;
    Node* current;
    Node* next;
  };
  
  Node* head;
  Node* tail;
  int my_size;
  
};

#endif
