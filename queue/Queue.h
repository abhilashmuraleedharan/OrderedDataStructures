/*
 * Simple Queue Implementation using a Doubly Linked List
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */
#include <exception>
#include <iostream>

template <typename T>
class Queue {
   public:
      Queue() : head_(nullptr), tail_(nullptr) { }
      
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
      
      const T & pop();   // Returns the front node data and deletes the node from the queue.
      
      bool empty();   // Returns TRUE if the queue is empty, else returns FALSE.
      
      const T & front();   // Returns the front node data. 

   private:
      class QueueNode {
         public:
            const T & data;       // Stores node data
            QueueNode *next;      // To point to next node in the queue
            QueueNode *previous;  // To point to previous node in the queue
            
            QueueNode(const T & data) : data(data), next(nullptr), previous(nullptr) { }
      };
      
      QueueNode *head_;  // To keep track of the front of the queue
      QueueNode *tail_;  // To keep track of the tail of the queue
};

template <typename T> 
void Queue<T>::push(const T & data) {
   QueueNode *node = new QueueNode(data);
   if (head_ == nullptr && tail_ == nullptr) {
      // This is the very first node
      node->next = nullptr;
      node->previous = nullptr;
      head_ = node;
      tail_ = node;
   } else {
      // Queue is not empty
      node->previous = tail_;
      node->next = nullptr;
      tail_->next = node;
      tail_ = node;
   }
}

template <typename T>
const T & Queue<T>::pop() {
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
      return data;
   } else {
      std::cerr << "Tried to pop an empty queue!!!" << std::endl;
      throw std::runtime_error("Pop failed since queue is empty.");   
   }
}

template <typename T>
bool Queue<T>::empty() {
   return (head_ == nullptr && tail_ == nullptr);
}

template <typename T>
const T & Queue<T>::front() {
   if (!empty()) {
      return head_->data;
   } else {
      std::cerr << "Queue is empty!!!" << std::endl;
      throw std::runtime_error("Queue is empty");
   }
}
