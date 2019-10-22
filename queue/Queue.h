/*
 * Simple Queue Implementation using a Doubly Linked List
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */
#pragma once

#include <exception>
#include <iostream>

template <typename T>
class Queue {
   public:
      Queue() : head_(nullptr), tail_(nullptr), size_(0) { }
      
      ~Queue() {
         QueueNode *thru = head_;
         while(thru != nullptr) {
            QueueNode *toDelete = thru;
            thru = thru->next;
            delete toDelete;
            toDelete = nullptr;
         }
      }

      void push(const T & data);   // Pushes a new node with given data at the back of the queue.
      
      void pop();   // Deletes a node from the front of the queue.
      
      bool empty() const;   // Returns TRUE if the queue is empty, else returns FALSE.
      
      const T & front() const;   // Returns the front node data.

      const T & back() const;    // Returns the last node data.

      unsigned size() const;   // Returns the size of the queue. 

   private:
      class QueueNode {
         public:
            const T & data;       // Stores node data.
            QueueNode *next;      // Points to next node in the queue.
            QueueNode *previous;  // Points to previous node in the queue.
            
            QueueNode(const T & data) : data(data), next(nullptr), previous(nullptr) { }
      };
      
      QueueNode *head_;  // Points to the node at the front of the queue.
      QueueNode *tail_;  // Points to the node at the back of the queue.
      unsigned size_;    // Stores the size of the queue
      
};

/*
 * Pushes a new node with given data at the back of the queue.
 */
template <typename T> 
void Queue<T>::push(const T & data) {

   QueueNode *node = new QueueNode(data);

   if (empty()) {
      // This is the very first node
      head_ = node;
      tail_ = node;
   } else {
      // Queue is not empty
      node->previous = tail_;
      node->next = nullptr;
      tail_->next = node;
      tail_ = node;
   }
   // Increment the queue size counter
   size_++;
}

/*
 * Deletes a node from the front of the queue
 */
template <typename T>
void Queue<T>::pop() {

   if (!empty()) {
      const T & data = head_->data;
      QueueNode *toDelete = head_;

      if (head_ == tail_) {
         // This is the last node in the queue
         head_ = nullptr;
         tail_ = nullptr;
      } else {
         head_ = head_->next;
         head_->previous = nullptr;
      }
      delete toDelete;
      toDelete = nullptr;

      // Decrement the queue size counter
      size_--;
   } else {
      std::cerr << "Nothing to pop. Queue is empty!" << std::endl;
   } 
}

/*
 * Checks whether the queue is empty.
 * Returns TRUE if the queue is empty, else returns FALSE
 */
template <typename T>
bool Queue<T>::empty() const {
   return (head_ == nullptr && tail_ == nullptr);
}

/*
 * Returns the front node data
 */
template <typename T>
const T & Queue<T>::front() const {

   if (!empty()) {
      return head_->data;
   } else {
      std::cerr << "Queue is empty!!!" << std::endl;
      throw std::runtime_error("Queue is empty");
   }
}

/*
 * Returns the last node data.
 */
template <typename T>
const T & Queue<T>::back() const {

   if (!empty()) {
      return tail_->data;
   } else {
      std::cerr << "Queue is empty!!!" << std::endl;
      throw std::runtime_error("Queue is empty");
   }
}

/*
 *  Returns the size of the queue
 */
template <typename T>
unsigned Queue<T>::size() const {
   return size_;
}
