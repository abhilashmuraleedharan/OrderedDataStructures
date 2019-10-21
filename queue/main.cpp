/*
 * Program that demonstrates the Queue Class Methods
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */
#include "Queue.h"
#include <iostream>

int main() {
   // Create a queue:
   Queue<std::string> q;

   // Add several strings to the queue:
   q.push( "Orange" );
   q.push( "Blue" );
   q.push( "Green" );

   // Print the front of the queue out and pop it off:
   std::cout << "First pop(): " << q.front() << std::endl;
   q.pop();

   // Add another string and then print the front of the queue before popping it off:
   q.push( "Red" );
   std::cout << "Second pop(): " << q.front() << std::endl;
   q.pop();

   // Check if queue is empty
   std::cout << "Is Queue empty? " << std::endl;
   q.empty() ? std::cout << "Yes it is!" : std::cout << "No, it's not!";
   std::cout << std::endl; 

   return 0;   
}
