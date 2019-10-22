/********************************************************
 *  
 *  Simple Linked List, templated List Class
 *  
 *  Author: Abhilash Muraleedharan
 *  Email: amuraleedharan13@gmail.com
 *
 *******************************************************/

// Redundantly making sure that List.h is included. Since List.h is written
// to include this file, we won't need to explicitly include List.hpp in
// the main.cpp file.

#include <iostream>
#include "List.h"

/*
 * Overload operator[] to access an element of the list
 * like we do in case of a regular array.
 * For e.g. to access element at index 3, call list[3]
 */
template <typename T>
const T & List<T>::operator[](unsigned index) {
   ListNode *thru = head_;
   while (index > 0 && thru->next != nullptr) {
      thru = thru->next;
      index--;
   }
   return thru->data;
}

/*
 * Insert the given data as an element at the front of the list.
 */
template <typename T>
void List<T>::insertAtFront(const T & data) {
   ListNode *node = new ListNode(data);
   node->next = head_;
   head_ = node;
   size_++;
}

/*
 * Insert given data as an element after the given index in the list.
 * Return without doing anything if given index is invalid.
 */
template <typename T>
void List<T>::insertAfter(const T & data, unsigned index) {
   if (index < 0 || index > size_) {
      std::cout << "Invalid index" << std::endl;
      return;
   } 
   ListNode *node = new ListNode(data);
   ListNode *thru = head_;
   while (index > 0 && thru->next != nullptr) {
       thru = thru->next;
       index--;
   }
   node->next = thru->next;
   thru->next = node;
   size_++;
}

/*
 * Delete the element present at a given index in the list.
 * Return without doing anything if given index is invalid.
 */
template <typename T>
void List<T>::deleteNode(unsigned index) {
   if (index < 0 || index > size_) {
      std::cout << "Invalid index" << std::endl;
      return;
   }
   ListNode *thru = head_;
   if (index == 0) {
      head_ = thru->next;
      delete thru;
      thru = nullptr;
      size_--;
      return;
   }
   ListNode *before = nullptr; // To refer the immediate previous node
                               // of the node to be deleted.
   while (index > 0 && thru->next != nullptr) {
       if (index == 1) {
          before = thru;
       }
       thru = thru->next;
       index--;
   }
   before->next = thru->next;
   delete thru;
   thru = nullptr;
   size_--;
}

/*
 * Attach the given data as an element at the end of the list.
 */ 
template <typename T>
void List<T>::append(const T & data) {
   ListNode *node = new ListNode(data);
   ListNode *thru = head_;
   while (thru->next != nullptr) {
       thru = thru->next;
   }
   thru->next = node;
   node->next = nullptr;
   size_++;
}

/*
 * Checks if there is an element in the list that matches the given data.
 * Returns the address of the matching element if present.
 * Returns nullptr otherwise.
 */
template <typename T>
typename List<T>::ListNode * List<T>::_find(const T & data) {
   ListNode *thru = head_;
   while (thru != nullptr) {
       if (thru->data == data) {
          return thru;
       }
       thru = thru->next;
   }
   return nullptr;
}

/*
 * Checks if given data is present as an element in the list.
 * If present, returns the index at which the matching element is present.
 * Else return -1.
 */
template <typename T>
int List<T>::find(const T & data) {
   ListNode *temp = _find(data);
   if (temp != nullptr) {
      return _index(temp); 
   } else {
      return -1;
   }
}

/*
 * Returns the current number of elements in the list.
 */
template <typename T>
unsigned List<T>::size() {
   return size_;
}

/*
 * Helper method that determines the index of the given element.
 * Return -1 if element is not present in the list.
 */
template <typename T>
int List<T>::_index(const List<T>::ListNode * node) {
   ListNode *thru = head_;
   int index = 0;
   while (thru != nullptr) {
      if (thru->data == node->data) {
         return index;
      }
      thru = thru->next;
      index++;
   }
   return -1;
}

/*
 * Print all the elements in the list.
 */
template <typename T>
void List<T>::print() {
   if (size_ == 0) {
      std::cout << "Empty list" << std::endl;
      return;
   }
   for (unsigned i = 0; i < size_; i++) {
      std::cout << "[ " << i << " ] : " << (*this)[i] << std::endl;
   }
}
