/*
 * Class outline for a binary tree traversal example
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */

#pragma once

#include "BinaryTree.h"

/* 
 * The contents of vector "contents" will be arranged in the tree level by
 * level, from left to right, as a complete binary tree. For example,
 * passing in a vector of integers {1, 2, 3, 4} will store a copy of 1 in a
 * root node, 2 will be the left child of the 1, 3 will be the right child
 * of the 1, and 4 will be the left child of the 2.
 */
template <typename T>
void BinaryTree<T>::createCompleteTree(const std::vector<T> & contents) {
   // Empty the tree
   destroyWholeTree();

   // Return immediately if the vector passed in is empty
   if (contents.empty()) {
      return;
   }

   /* 
    * Atleast one node is present in the tree.
    * Make the first item as root node.
    */
   root_ = new TreeNode(contents[0]);

   /*
    * Make a queue for the next child pointers that we need to assign data
    * to, based on loading the data from the input vector into a complete
    * binary tree, layer by layer.
    */
   std::queue<TreeNode**> childPtrPtrQueue;

   // Push the root node's left and right child pointers onto the queue
   childPtrPtrQueue.push(&(root_->left));
   childPtrPtrQueue.push(&(root_->right));

   /* 
    * Put in the rest of the layers by looping over the remaining contents 
    * and popping the next children pointers from the queue.
    */
   for(unsigned i = 1; i < contents.size(); i++) {
      TreeNode **childPtrPtr = childPtrPtrQueue.front();
      childPtrPtrQueue.pop();
      TreeNode *& actualChildPtr = *childPtrPtr;  
      actualChildPtr = new TreeNode(contents[i]);
      childPtrPtrQueue.push(&(actualChildPtr->left));
      childPtrPtrQueue.push(&(actualChildPtr->right));
   }
}

// Traversal Functions

template <typename T>
void BinaryTree<T>::preOrder(TreeNode *cur) {
   if (cur) {
      /* 
       * Act upon this node first, by "shouting it out" now,
       * as a way of officially visiting this node at this time
       * as part of the intended "pre-order" traversal.
       */
      shout(cur);

      // Then recurse on the left
      preOrder(cur->left);

      // Then recurse on the right
      preOrder(cur->right);
   }
}

template <typename T>
void BinaryTree<T>::inOrder(TreeNode *cur) {
   if (cur) {
      // First, recurse on the left
      inOrder(cur->left);

      // Now act upon this node by shouting it as part of "in-order" traversal.
      shout(cur);

      // Lastly, recurse on the right
      inOrder(cur->right);
   }
}

template <typename T>
void BinaryTree<T>::postOrder(TreeNode *cur) {
   if (cur) {
      // First, recurse on the left
      postOrder(cur->left);

      // Next, recurse on the right
      postOrder(cur->right);

      // Now act upon this node last, since it's a "post-order" traversal.
      shout(cur);
   }
}
