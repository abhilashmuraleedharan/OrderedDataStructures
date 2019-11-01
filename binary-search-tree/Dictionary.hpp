/*
 * Dictionary Class implementation using Binary Search Tree.
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 */

#pragma once

#include "Dictionary.h"

/*
 * If key is present in the dictionary, returns the associated data.
 * Throws error if key not found.
 */
template <typename K, typename D>
const D & Dictionary<K, D>::find(const K & key) {
  TreeNode *& node = _find(key, head_);
  if (node == nullptr) {
     // This means this key is not present in the dictionary
     throw std::runtime_error("error: key not found");
  } 
  return node->data; 
}

/*
 * Inserts a new node containing the unique key and data into the dictionary.
 * Throws error if the given key is a duplicate.
 */
template <typename K, typename D>
void Dictionary<K, D>::insert(const K & key, const D & data) {
   // Find the place where the item should go.
   TreeNode *& node = _find(key, head_);
   if(node) {
      // This means the key is already present.
      throw std::runtime_error("error: failed to insert since the given key is already present");
   } else {
      // This is a unique key. Can be inserted.
      node = new TreeNode(key, data);
   }
}

/*
 * Removes the node containing matching key from the dictionary 
 * if key is valid. Returns the removed node data.
 * Throws error if given an invalid key.
 */
template <typename K, typename D>
const D & Dictionary<K, D>::remove(const K & key) {
   // Check if the given key is a valid one.
   TreeNode *& node = _find(key, head_);
   if (node == nullptr) {
      // This key is not present in the dictionary.
      throw std::runtime_error("error: non-existent key");
   } else {
      // Given key is valid
      try {
         return _remove(node);
      } catch (const std::runtime_error & e) {
         throw std::runtime_error("Caught exception with error message: " + std::string(e.what()));
      }
   }
}

/*
 * Returns TRUE if the dictionary is empty, else returns FALSE
 */
template <typename K, typename D>
bool Dictionary<K, D>::empty() const {
   return (head_ == nullptr) ? true : false;
}

/*
 * Deletes all the nodes present in the tree
 */
template <typename K, typename D>
void Dictionary<K, D>::deleteWholeTree() {
   while(head_) {
      try {
         remove(head_->key);
      } catch (const std::runtime_error & e) {
         std::cout << "\nCaught exception with error message: " << e.what() << std::endl;
      }
   }
}

/*
 * Wrapper function for _printInOrder()
 */
template <typename K, typename D>
void Dictionary<K, D>::printInOrder() const {
   _printInOrder(head_);
}

/*
 * Print the tree contents to std::cout 
 * by performing an in-order traversal.
 */
template <typename K, typename D>
void Dictionary<K, D>::_printInOrder(TreeNode *cur) const {
   if (cur == nullptr) {
      std::cout << " ";
      return; 
   }
   // Recurse left
   _printInOrder(cur->left);
   // Print the Key:Data value of node
   std::cout << "[" << cur->key << " : " << cur->data << "]";
   // Recurse right
   _printInOrder(cur->right);
}

/*
 * Traverses the binary search tree and returns the reference to 
 * the pointer containing the address of node having the matching key.
 * Returns nullptr if the key is absent in the tree.
 */
template <typename K, typename D>
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_find(
   const K & key, TreeNode *& cur) const {
   if (cur == nullptr) { return cur; }  // key not found
   else if (key == cur->key) { return cur; }  // Matching node found
   else if (key < cur->key) { return _find(key, cur->left); }   // Traverse left sub tree
   else { return _find(key, cur->right); }  // Traverse right sub tree  
}

/*
 * Removes the node pointed to by the argument 
 * and returns the deleted node data.
 */
template <typename K, typename D> 
const D & Dictionary<K, D>::_remove(TreeNode *& node) {

   if (node == nullptr) {
      // This is an error scenario. Throw error.
      throw std::runtime_error("error: Called _remove() on non-existent node");
   }

   // This is a zero child node remove
   if (node->left == nullptr && node->right == nullptr) {
      // This is a leaf node. Do a direct delete
      const D & data = node->data;
      delete node;
      node = nullptr;
      return data;
   // This is a one child node remove
   } else if (node->left != nullptr && node->right == nullptr) {
      // Only left child is present. Delete node while maintaining link to left child.
      const D & data = node->data;
      TreeNode *temp = node;
      node = node->left;
      delete temp;
      return data;
   } else if (node->left == nullptr && node->right != nullptr) {
      // Only right child is present. Delete node while maintaining the link to right child. 
      const D & data = node->data;
      TreeNode *temp = node;
      node = node->right;
      delete temp;
      return data;
   // This is a 2 child node remove 
   } else {
      /* 
       * To maintain the balance of the tree, find the In-Order-Predecessor of the node to be deleted.
       * Swap the IOP node with this node.
       * Delete the node in it's new position. 
       * (which can either be a zero child node delete or one child node delete).
       */
     
      // Find IOP Node
      TreeNode *& iop_node = _iop_of(node);
      if(!iop_node) { 
         // This is an error scenario. Throw error
         throw std::runtime_error("error: IOP not found");
      }

      // Swap the IOP node with node to be deleted
      try {
         TreeNode *& moved_node = _swap_nodes(node, iop_node);
         // Recurse to remove the original targeted node in its updated position
         return _remove(moved_node);
      } catch (const std::runtime_error & e) {
         throw std::runtime_error("Caught exception with error message: " + std::string(e.what()));
      }
   }
}

/*
 * Helper function used by _remove()
 * Returns the In-Order-Predecessor of the given node in tree.
 * 
 * This routine uses the idea that,
 * "The IOP of a node will always be the right-most node
 *  in it's left sub-tree." 
 */
template <typename K, typename D>  
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_iop_of(
   TreeNode *& cur) const {
   if (cur == nullptr) { 
      // This is an error scenario. Return the cur back
      return cur;
   } else if (cur->left == nullptr) {
      // There is no left sub-tree. Return cur->left
      return cur->left;
   } else {
      // There is a left subtree. Find the rightmost node.
      return _rightmost_of(cur->left);
   }
}

/*
 * Helper function used by _iop_of()
 * Returns the reference of the pointer to right-most TreeNode in a sub-tree
 */
template <typename K, typename D>
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_rightmost_of(
   TreeNode *& cur) const {
   if (cur == nullptr) {
      return cur;
   }
   if (cur->right == nullptr) {
      // This is the right-most node. Return the same.
      return cur;
   }
   // Recursively traverse to the right-most node of the tree.
   return _rightmost_of(cur->right);
}

/*
 * Helper function used by _remove() 
 * Swap the two given nodes of the tree in their place.
 */
template <typename K, typename D>
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_swap_nodes(
   TreeNode *& node1, TreeNode *& node2) {
   if (node1 == nullptr || node2 == nullptr) {
      // This is an error scenario. Throw error.
      throw std::runtime_error("error: swap failed as one or both nodes has reference to a null pointer");
   }

   // Store the original references in temporary variables
   TreeNode *orig_node1 = node1;
   TreeNode *orig_node2 = node2;

   // Handle the case when the nodes are adjacent to each other.
   if (node1->left == node2) {
      std::swap(node1->right, node2->right);
      node1->left = orig_node2->left;
      orig_node2->left = node1;
      node1 = orig_node2;
      return node1->left;
   } else if (node1->right == node2) {
      std::swap(node1->left, node2->left);
      node1->right = orig_node2->right;
      orig_node2->right = node1;
      node1 = orig_node2;
      return node1->right;
   } else if (node2->left == node1) {
      std::swap(node2->right, node1->right);
      node2->left = orig_node1->left;
      orig_node1->left = node2;
      node2 = orig_node1;
      return node2->left;
   } else if (node2->right == node1) {
      std::swap(node2->left, node1->left);
      node2->right = orig_node1->right;
      orig_node1->right = node2;
      node2 = orig_node1;
      return node2->right;
   // Handle the case when the nodes are not adjacent.
   } else {
      std::swap(node1->left, node2->left);
      std::swap(node1->right, node2->right);
      std::swap(node1, node2);
      return node2; // Return the new reference of the moved node.
   }
}

