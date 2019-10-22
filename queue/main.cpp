/*
 * Program that demonstrates the Queue Class Methods
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */
#include <iostream>
#include "Queue.h"

int main() {
   // Create a queue:
   Queue<std::string> q;
   std::cout << "Created an empty queue of strings" << std::endl;

   // Add several strings to the queue:
   std::cout << "Pushing string \"Orange\" to the queue" << std::endl;
   q.push( "Orange" );
   std::cout << "Pushing string \"Blue\" to the queue" << std::endl;
   q.push( "Blue" );
   std::cout << "Pushing string \"Green\" to the queue" << std::endl;
   q.push( "Green" );

   // Print the front of the queue and then pop it 
   std::cout << "First pop(): " << q.front() << std::endl;
   q.pop();

   // Add another string and then print the front of the queue before popping it off:
   std::cout << "Pushing string \"Red\" to the queue" << std::endl;
   q.push( "Red" );
   std::cout << "Second pop(): " << q.front() << std::endl;
   q.pop();

   std::cout << "Size of the queue: " << q.size() << std::endl;
   std::cout << "Last item in the queue: " << q.back() << std::endl;

   // Check if queue is empty
   std::cout << "Is Queue empty? " << std::endl;
   q.empty() ? std::cout << "Yes" : std::cout << "No, current queue size is " << q.size();
   std::cout << std::endl; 

   return 0;   
}
