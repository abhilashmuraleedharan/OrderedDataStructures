/*
 * Dictionary Class implementation using Binary Search Tree.
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 */

#pragma once

 // For std::runtime_error
#include <stdexcept>
 // For std::swap
#include <utility>
 // For std::cout
#include <iostream>


template <typename K, typename D>
class Dictionary {
   public:
      Dictionary() : head_(nullptr) { }

      const D & find(const K & key);  // Returns associated data, if given key is 
                                      // present in the Dictionary.
      void insert(const K & key, const D & data);  // Inserts a node containing a key:data pair i
                                                   // into the Dictionary.
      const D & remove(const K & key);  // Removes the node having matching key from the Dictionary.
      
      bool empty() const;  // Returns TRUE if the Dictionary is empty, else returns FALSE.

      ~Dictionary() {
         deleteWholeTree();
      }

   private:
      // Binary Search TreeNode Class
      class TreeNode {
         public:
            const K & key;   // Stores the unique key value.
            const D & data;  // Stores the associated data value. 
            TreeNode *left, *right;  // Points to the left and right child respectively.

            TreeNode(const K & key, const D & data) 
               : key(key), data(data), left(nullptr), right(nullptr) { }
 
      };

      TreeNode * head_;  // Points to the root node of the Binary Search Tree.
      
      TreeNode *& _find(const K & key, TreeNode *& cur) const;  // Finds and returns the matching node reference from the tree.

      const D & _remove(TreeNode *& node);  // Removes the given node from the tree.

      // Below three functions are helper functions for _remove() 
      TreeNode *& _iop_of(TreeNode *& cur) const;  // Finds the In-Order-Predecessor of given node.
      TreeNode *& _rightmost_of(TreeNode *& cur) const;  // Finds the right-most node of a given sub-tree.
      TreeNode *& _swap_nodes(TreeNode *& node1, TreeNode *& node2);  // Swap the two given nodes of tree in place.
      
      void _printInOrder(TreeNode *node) const;  // Performs an In-Order traversal of the tree printing the key value
                                                 // as it visits each node.

   public: 
      void printInOrder() const;  // Prints all the key:data entries in the Dictionary in order.

      void deleteWholeTree();  // Deletes all the nodes present in the Binary Search Tree.

};

// Including the header file that contains the templated function definitions
#include "Dictionary.hpp" 
