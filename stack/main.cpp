/*
 * Program that demonstrates the Stack Class Methods
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */
#include "Stack.h"
#include <iostream>

int main() {
   // Create a stack:
   Stack<std::string> s;
   std::cout << "Created an empty stack of strings" << std::endl;

   // Add several strings to the stack:
   std::cout << "Pushing string \"Orange\" on to stack" << std::endl;
   s.push( "Orange" );
   std::cout << "Pushing string \"Blue\" on to stack" << std::endl;
   s.push( "Blue" );
   std::cout << "Pushing string \"Green\" on to stack" << std::endl;
   s.push( "Green" );

   // Print the top of the stack and then pop it 
   std::cout << "First pop(): " << s.top() << std::endl;
   s.pop();

   // Add another string on to stack and then print the top of the stack before popping it off:
   std::cout << "Pushing string \"Red\" on to stack" << std::endl;
   s.push( "Red" );
   std::cout << "Second pop(): " << s.top() << std::endl;
   s.pop();

   std::cout << "Size of the stack: " << s.size() << std::endl;

   // Check if stack is empty
   std::cout << "Is Stack empty? " << std::endl;
   s.empty() ? std::cout << "Yes" : std::cout << "No, current stack size is " << s.size();
   std::cout << std::endl; 

   return 0;   
}
