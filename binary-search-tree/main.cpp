/*
 * Dictionary implemented using a Binary Search Tree example.
 * 
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 */

#include <string>
#include <iostream>
#include <vector>

#include "Dictionary.h"

int main() {

  // Initializing a vector 100 elements long, filled with 0 values
  const int V_SIZE = 100;
  std::vector<int> v(V_SIZE, 0);

  // Reassigning each item to hold a value matching its index
  for (int i = 0; i < V_SIZE; i++) {
    v[i] = i;
  }

  // Creating some string constants to add as values into Dictionary
  const std::string str_thirty_seven("thirty seven");
  const std::string str_nineteen("nineteen");
  const std::string str_fifty_one("fifty one");
  const std::string str_fifty_five("fifty five");
  const std::string str_four("four");
  const std::string str_eleven("eleven");
  const std::string str_twenty("twenty");
  const std::string str_two("two");

  /* 
   * Creating an inner scoping block here to restrict the lifetime of the
   * tree to be shorter than that of the ints and strings, since the tree
   * will directly reference those items. This way, the ints and strings will
   * be destroyed only after the tree has already gone out of scope at the
   * end, so the tree will be destroyed before the objects that it refers to.
   */
  {
    Dictionary<int, std::string> t;

    // Enabling conversion from bool to strings "true" and "false" for the std::cout stream. 
    std::cout << std::boolalpha;
    std::cout << "Dictionary empty at the beginning? " << t.empty() << std::endl;

    std::cout << "Inserting items..." << std::endl;

    t.insert(v[37], str_thirty_seven);
    t.insert(v[19], str_nineteen);
    t.insert(v[51], str_fifty_one);
    t.insert(v[55], str_fifty_five);
    t.insert(v[4], str_four);
    t.insert(v[11], str_eleven);
    t.insert(v[20], str_twenty);
    t.insert(v[2], str_two);

    std::cout << "Dictionary empty after insertions? " << t.empty() << std::endl;

    std::cout << "Current tree contents in order:" << std::endl;
    t.printInOrder();
    std::cout << std::endl;

    std::cout << "Using find to show that 51 has been inserted:" << std::endl;
    std::cout << "t.find(51): " << t.find(51) << std::endl;

    std::cout << "Trying to remove some items:" << std::endl;
    std::cout << "t.remove(11): " << t.remove(11) << " (zero child remove)" << std::endl;
    std::cout << "t.remove(51): " << t.remove(51) << " (one child remove)" << std::endl;
    std::cout << "t.remove(19): " << t.remove(19) << " (two child remove)" << std::endl;

    std::cout << "Current tree contents in order:" << std::endl;
    t.printInOrder();
    std::cout << std::endl;

    try {
      std::cout << "Attempting to find a non-existent item, 51: " << std::endl;
      std::cout << "t.find(51): " << t.find(51) << std::endl;
    }
    catch (const std::runtime_error& e) {
      std::cout << "\nCaught exception with error message: " << e.what() << std::endl;
    }

    try {
      std::cout << "Attempting to remove a non-existent item, 99: " << std::endl;
      std::cout << "t.remove(99): " << t.remove(99) << std::endl;
    }
    catch (const std::runtime_error& e) {
      std::cout << "\nCaught exception with error message: " << e.what() << std::endl;
    }

    try {
      std::cout << "Attempting to insert an item with an existing key, 2: " << std::endl;
      t.insert(v[2], str_two);
    }
    catch (const std::runtime_error& e) {
      std::cout << "Caught exception with error message: " << e.what() << std::endl;
    }
  }

  std::cout << "Exiting program normally." << std::endl;

  return 0;
}
