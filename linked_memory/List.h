/********************************************************
 *
 * Simple Linked List, templated List Class
 *
 * Author: Abhilash Muraleedharan
 * Email: amuraleedharan13@gmail.com
 *
 *******************************************************/

#pragma once

template <typename T>
class List {
   public:
      const T & operator[](unsigned index); /*
                                             * Overloads operator[] to access a node of the list
                                             * For e.g. to access element at index 3, call list[3]
                                             */

      void insertAtFront(const T & data); // Inserts the given data as a node at the front of the list.

      void insertAfter(const T & data, unsigned index); /*
                                                         * Inserts given data as a node after 
                                                         * the given index in the list.
                                                         * Returns without doing anything if 
                                                         * given index is invalid.
                                                         */

      void deleteNode(unsigned index); /*
                                        * Deletes the node present at the given index in the list.
                                        * Returns without doing anything if given index is invalid.
                                        */

      void append(const T & data); // Attaches the given data as a node at the end of the list.

      int  find(const T & data); /*
                                  * Checks if given data is present as an element in the list.
                                  * If present, returns the index at which the matching element is present.
                                  * Else returns -1.
                                  */
      
      unsigned size(); // Returns the current number of elements in the list.

      void print(); // Prints all the elements in the list.

      List() : head_(nullptr), size_(0) { }

      ~List() {
         ListNode *thru = head_;
         while(thru != nullptr) {
            ListNode *toDelete = thru;
            thru = thru->next;
            delete toDelete;
            toDelete = nullptr;
         }
      }

   private:
      class ListNode {
         public:
            const T & data;
            ListNode *next;
            ListNode(const T & data) : data(data), next(nullptr) { }
      };

      ListNode *head_;  // Keeps track of the first node in the list.

      ListNode * _find(const T & data);  /* 
                                          * Checks if there is a node in the list that matches the given data.
                                          * Returns the address of the matching node if present.
                                          * Returns nullptr otherwise.
                                          */

      int _index(const ListNode * node); /*
                                          * Helper method that determines the index of the given node.
                                          * Returns -1 if given node is not present in the list.
                                          */

      unsigned size_;  // To keep track of the size of the list.
                       // Needs to be updated everytime a node is added / deleted.
};

// Finish including the rest of the header from the additional header file.
// This is just done to spread out writing among more manageable files.
#include "List.hpp"
