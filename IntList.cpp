/**   @file IntList.cpp    
      @author Matt Hoendorf <heondomd@mail.uc.edu>
      @date 10-04-14
      @version 0.01   
      
      This IntList class represents a singly linked-list storing integers.
      
      Various class members need to be implemented.
      
**/
#include <iostream>
#include <sstream>
#include "IntList.h"

using namespace std;

IntList::IntList(){
  head = NULL;
  tail = NULL;
  my_size = 0;
}

IntList::~IntList(){
  delete head;
}

void IntList::push_front(int value){
  Node* temp = new Node;  // Gets a new node
  if(my_size>=1){
    temp->next = head;      // Attach the new node to the beginning
    temp->value = value;
    tail = temp->next;    // of the list.
  }
  else{
    temp->value = value;
    tail = temp;
  }
  head = temp;            // Set head to point to the new node
  my_size++;
}

void IntList::push_back(int value){
  if(head == NULL){
    head = new Node;
    head->next = NULL;
    head->value = value;
    tail = head;
    my_size++;
    return;
  }
    // 1 or more nodes;
  Node* temp = new Node;
  tail->next = temp;
  tail = temp;
  temp->value = value;
  temp->next = NULL;
  my_size++;
}

bool IntList::setAt(int value, int location){
  if(location < 0){
    location = my_size + location;
  }
  if(location >= my_size){
    return false;
  }
  Node* temp = head;
  while(temp != NULL && location != 0){
    temp = temp->next;
    location--;
  }
  // temp should be the one we want OR past the end
  if(temp != NULL){
    temp->value = value;
    return true;
  }
  return false;
}

int IntList::getAt(int location) const{
  if(location < 0){
    location = my_size + location;
  }
  if(location >= my_size){
    return 0;
  }
  Node* temp = head;
  while(temp != NULL && location != 0){
    temp = temp->next;
    location--;
  }
  // temp should be the one we want OR past the end
  if(temp != NULL){
    return temp->value;
  }
  return 0;
}

bool IntList::insert(int value, int location){
  if(location < 0){
    location = my_size + location;
  }
  if(location > my_size){
    return false;
  }
  int i = 0;
  Node* temp = head;
  if(temp == NULL){
    push_back(value);
    return true;
  }
  else{
    while(temp != NULL){
      if(temp->value<value){
        i++;
        temp = temp->next;
      }
    }
    if(i == 0 || location == my_size){
      push_back(value);
    }
    else if(i<my_size){
      setAt(value,i++);
    }
    else{
      push_front(value);
    }
    return true;
  }
  return false;
}
              
bool IntList::remove(int location){
  Node *prev = 0, *current = head;
  int i = 0;
  if(location < 0){
    location = my_size + location;
  }
  if(location > my_size){
    return false;
  }
  while(current != NULL)
  {
    if (i == location){ // set loc = next loc
      if(prev){
        prev->next = current->next;
      }
      if(current == head){
        head = current->next;
      }
      delete current;
      current = NULL;
      my_size--;
      i++;
      return true;
    }
    else{
      prev = current;
      current = current->next;
      i++;
    }
  }
  return false;
}

string IntList::print() const{
  Node* temp = head;
  int i = 0;
  string str;
  while(temp != NULL){
    str.push_back('[');
    string s;
    string t;
    int num = temp->value;
    while(num/10!=0){
      t.push_back(num%10+48);
      s.insert(0, t);
      t = "";
      num = num/10;
    }
    t.push_back(num+48); 
    s.insert(0, t);
    str.append(s);
    str.push_back(']');
    str.push_back(' ');
    temp = temp->next;
    i++;
  }
  return str;
}

unsigned int IntList::size() const{
  return my_size;
}
