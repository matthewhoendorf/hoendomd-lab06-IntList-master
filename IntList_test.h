/*
  IntList_test.h
  Unit tests for Lab6, linked-list.
  
*/

#include "IntList.h"
#include <stdexcept>
#include <sstream>

#include <cxxtest/TestSuite.h>

class IntListTest : public CxxTest::TestSuite {
public:
  
  void testPushFront1() {
    IntList a;
    a.push_front(1);
    a.push_front(2);
    TS_ASSERT_EQUALS(a.size(), 2);
  }

  void testPushFront2() {
    IntList a;
    a.push_front(1);
    a.push_front(2);
    TS_ASSERT_EQUALS(a.getAt(0), 2);
  }
  
  void testPushFront3() {
    IntList a;
    a.push_front(1);
    a.push_front(2);
    TS_ASSERT_EQUALS(a.getAt(1), 1);
  }
  
  void testPushBack1() {
    IntList a;
    a.push_back(1);
    a.push_back(2);
    TS_ASSERT_EQUALS(a.size(), 2);
  }

  void testPushBack2() {
    IntList a;
    a.push_back(1);
    a.push_back(2);
    TS_ASSERT_EQUALS(a.getAt(0), 1);
  }
  
  void testPushBack3() {
    IntList a;
    a.push_back(1);
    a.push_back(2);
    TS_ASSERT_EQUALS(a.getAt(1), 2);
  }
  
  void testSetAt1() {
    IntList a;
    a.push_front(0);
    a.push_front(0);
    a.push_front(0);
    a.setAt(12,0);
    a.setAt(34,1);
    a.setAt(56,2);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  
  void testSetAt2() {
    IntList a;
    a.setAt(12,0);
    a.setAt(34,1);
    a.setAt(56,2);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testSetAt3() {
    IntList a;
    a.push_front(0);
    a.push_front(0);
    a.push_front(0);
    a.setAt(12,0);
    a.setAt(34,1);
    a.setAt(56,2);
    TS_ASSERT_EQUALS(a.getAt(0), 12);
  }
  
  void testSetAt4() {
    IntList a;
    a.push_front(0);
    a.push_front(0);
    a.push_front(0);
    a.setAt(12,0);
    a.setAt(34,1);
    a.setAt(56,2);
    a.push_front(0);
    TS_ASSERT_EQUALS(a.getAt(2), 34);
  }
  
  void testInsert1() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.insert(1337,0);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testInsert2() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.insert(1337,0);
    TS_ASSERT_EQUALS(a.getAt(0), 1337);
  }
  
  void testInsert3() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.insert(1337,0);
    TS_ASSERT_EQUALS(a.getAt(1), 12);
  }
  
  void testInsert4() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.insert(1337,3);
    TS_ASSERT_EQUALS(a.getAt(3), 1337);
  }
  
  void testInsert5() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    TS_ASSERT_EQUALS(a.insert(1337,3), true);
  }
  
  void testInsert6() {
    IntList a;
    a.insert(1337,0);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testInsert7() {
    IntList a;
    TS_ASSERT_EQUALS(a.insert(1337,0), true);
  }
  
  void testInsert8() {
    IntList a;
    a.insert(1337,1);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testInsert9() {
    IntList a;
    TS_ASSERT_EQUALS(a.insert(1337,1), false);
  }
  
  void testInsert10() {
    IntList a;
    a.insert(1337,-1);
    TS_ASSERT_EQUALS(a.getAt(0), 1337);
  }
    
  void testRemove1() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  
  void testRemove4() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.remove(2);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testRemove5() {
    IntList a;
    a.push_back(12);
    a.push_back(34);
    a.push_back(56);
    a.remove(2);
    TS_ASSERT_EQUALS(a.getAt(2), NULL);
  }
  
};
