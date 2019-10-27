/**
 * Examples of BinaryTree usage and some tree traversals
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 */

#include "BinaryTree.h"

int main() {

   // Example of traversals with a complete tree of integers
   BinaryTree<int> seven_tree({1,2,3,4,5,6,7});

   // We'll get a pointer to the root node of the tree.
   auto rootPtr = seven_tree.unsafe_getRootPtr();

   std::cout << "Example of pre-order traversal with a complete tree: " << std::endl;

   // Do the pre-order traversal now, which outputs the values:
   seven_tree.preOrder(rootPtr);
   std::cout << std::endl << std::endl;

   // Expected output:
   // 1 2 4 5 3 6 7

   std::cout << "Example of in-order traversal with a complete tree: " << std::endl;

   seven_tree.inOrder(rootPtr);
   std::cout << std::endl << std::endl;

   // Expected output:
   // 4 2 5 1 6 3 7

   std::cout << "Example of post-order traversal with a complete tree: " << std::endl;

   seven_tree.postOrder(rootPtr);
   std::cout << std::endl << std::endl;

   // Expected output:
   // 4 5 2 6 7 3 1

  return 0;
}
