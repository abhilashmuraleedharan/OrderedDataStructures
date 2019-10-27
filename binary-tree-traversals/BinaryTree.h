/*
 * Class outline for a binary tree traversal example
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */

#pragma once

#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTree {
   public:

      class TreeNode {
         public:
            T data;
            TreeNode *left, *right;
            TreeNode(const T & dataArg) : data(dataArg), left(nullptr), right(nullptr) { }
      };

      BinaryTree() : root_(nullptr) { }

      /* 
       * Inhibit the compiler from allowing a copy constructor or from creating an implicit
       * copy constructor for us. This prevent ourselves from accidently doing a shallow copy
       * with an implicity defined copy constructor.
       */
      BinaryTree(const BinaryTree<T> & other) = delete;

      ~BinaryTree() {
         destroyWholeTree();
      }
      
      /* 
       * This function let us build a "complete" binary tree based on the vector of intended
       * contents that's passed in.
       */
      void createCompleteTree(const std::vector<T> & contents);

      /* 
       * For convenience invoke createCompleteTree function from inside a constructor that takes the vector as
       * argument.
       */
      BinaryTree(const std::vector<T> & contents) : BinaryTree() {
         createCompleteTree(contents);
      }

      // This function deletes the subtree rooted at a specific node
      void destroySubtree(TreeNode *subtreeRootPtr) {
         if (!subtreeRootPtr) {
            return;
         }

         destroySubtree(subtreeRootPtr->left);
         destroySubtree(subtreeRootPtr->right);

         subtreeRootPtr->left = nullptr;
         subtreeRootPtr->right = nullptr;

         delete subtreeRootPtr;
      }
     
      // Wrapper for destroySubtree that just destroys everything from the root down
      void destroyWholeTree() {
        destroySubtree(root_);
        root_ = nullptr;
      }

      /* 
       * This function will "shout out" the value at the specified node.
       * The idea is to perform actual work on a given node by doing some action when it is
       * officially "visited" during the tree traversal (that is, when we are not just traversing 
       * past it temporarily to access other nodes). For the action in this case, we'll just 
       * print the value to the standard output stream, hence we call it "shout".
       */
      void shout(TreeNode *cur) {
         if (cur) {
            std::cout << cur->data;
         }
         std::cout << " ";
      }

      // Traversal functions
      void preOrder(TreeNode *cur);
      void inOrder(TreeNode *cur);
      void postOrder(TreeNode *cur);

      /* 
       * This function lets the user directly obtain the root pointer for
       * manual operations on the tree contents. (For the sake of this example)
       */
      TreeNode * unsafe_getRootPtr() {
         return root_;
      } 

   private:

      TreeNode *root_;

};

#include "BinaryTree.hpp" 
