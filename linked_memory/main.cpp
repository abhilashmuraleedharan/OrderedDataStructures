/*
 * Program to demonstrate the Single Linked List class List's Public methods
 */
#include <iostream>
#include "List.h"

int main() {
   std::cout << "Creating an integers list" << std::endl;
   List<int> list;

   std::cout << "Inserting element 33 at front..." << std::endl;
   list.insertAtFront(33);
   list.print();
   
   std::cout << "Inserting element 57 at front..." << std::endl;
   list.insertAtFront(57);
   list.print();
   
   std::cout << "Appending element 83 to the list..." << std::endl;
   list.append(83);
   list.print();
   
   std::cout << "Inserting element 27 after index 1..." << std::endl;
   list.insertAfter(27, 1);
   list.print();
   
   std::cout << "Try to insert element 27 after invalid index 5..." << std::endl;
   list.insertAfter(27, 5);
   list.print();
   
   std::cout << "Appending element 99 to the list..." << std::endl;
   list.append(99);
   list.print();
   std::cout << "List size = " << list.size() << std::endl;
   
   std::cout << "Deleting element at index 3..." << std::endl;
   list.deleteNode(3);
   list.print();
   std::cout << "List size = " << list.size() << std::endl;

   std::cout << "Inserting element 77 after index 0..." << std::endl;
   list.insertAfter(77, 0);
   list.print();

   std::cout << "Deleting element at index 0..." << std::endl;
   list.deleteNode(0);
   list.print();
   std::cout << "List size = " << list.size() << std::endl;
   
   std::cout << "Check if element 33 is present in the list..." << std::endl;
   int index = list.find(33);
   if (index != -1) {
      std::cout << "Element 33 is present in the list at index " << index << std::endl;
   } else {
      std::cout << "33 is not present in the list" << std::endl;
   }

   std::cout << "Check if element 99 is present in the list..." << std::endl;
   index = list.find(99);
   if (index != -1) {
      std::cout << "Element 99 is present in the list at index " << index << std::endl;
   } else {
      std::cout << "99 is not present in the list" << std::endl;
   }
  
   std::cout << "Check if element 21 is present in the list..." << std::endl;
   index = list.find(21);
   if (index != -1) {
      std::cout << "Element 21 is present in the list at index " << index << std::endl;
   } else {
      std::cout << "21 is not present in the list" << std::endl;
   }

   std::cout << "Try to delete an element at an invalid index -1..." << std::endl;
   list.deleteNode(-1);
   list.print();
   std::cout << "List size = " << list.size() << std::endl;

   return 0;
}
