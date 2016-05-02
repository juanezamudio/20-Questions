/**
 * C class that takes care of the functions needed to create a binary tree that
 * will be used as the animal game tree
 *
 * @author Juan Zamudio
 * @author David Cremins
 *
 * @date May 1, 2016
 *
 */
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: Add Javadoc comments for each of the functions below. See the header
// file in assingment 10 for an example of how the functions should be
// commented. All of the functions declared below have a corresponing method
// in Bailey's BinaryTree class. If you have trouble mathching functions in
// this file to methods in Bailey's class, please let us know.

/**
 * max string size length allowed
 */
#define MAX_STRING_SIZE 1000

/**
 * struct for the binary tree
 */
typedef struct binary_tree binary_tree;

// Constructors

/**
 * @brief creates an empty binary tree
 *
 * @return an empty tree node
 */
binary_tree *binary_tree_create();

/**
 * @brief Constructs a tree node with no children.  Value of the node
 * and subtrees are provided by the user
 *
 * @param str A non-null value to be referenced by node
 */
binary_tree *binary_tree_create_s(char *str);

/**
 * @brief Constructs a tree node with two children.  Value of the node
 * and subtrees are provided by the user.
 *
 * @param  str   A non-null value to be referenced by node
 * @param  left  The subtree to be left subtree of node
 * @param  right The subtree to be right subtree of node
 * @return       a tree referencing value and two subtrees
 */
binary_tree *binary_tree_create_stt(char *str, binary_tree *left,
                                    binary_tree *right);

// Destructor

/**
 * @brief deconstructs the tree
 *
 * @param self the binary tree
 */
void binary_tree_destroy(binary_tree *self);

// Setters

/**
 * @brief Update the left subtree of this node.  Parent of the left subtree is
 * updated consistently.  Existing subtree is detached
 *
 * @param self the binary tree
 * @param left The root of the new left subtree
 */
void binary_tree_set_left(binary_tree *self, binary_tree *left);

/**
 * @brief Update the right subtree of this node.  Parent of the right subtree is
 * updated consistently.  Existing subtree is detached
 *
 * @param self the binary tree
 * @param right The root of the new right subtree
 */
void binary_tree_set_right(binary_tree *self, binary_tree *right);

// Queries

/**
 * @brief returns true if the tree is empty
 *
 * @param  self the binary tree
 * @return      true iff the tree is empty
 */
bool binary_tree_is_empty(binary_tree *self);

/**
 * @brief returns true if the tree is a leaf
 *
 * @param  self the binary tree
 * @return      true iff the tree is a leaf
 */
bool binary_tree_is_leaf(binary_tree *self);

/**
 * @brief returns true if the node is a left child of the parent
 *
 * @param  self the binary tree
 * @return      true iff the node is a left child of the parent
 */
bool binary_tree_is_left(binary_tree *self);

/**
 * @brief returns true if the node is a right child of the parent
 *
 * @param  self the binary tree
 * @return      true iff the node is a right child of the parent
 */
bool binary_tree_is_right(binary_tree *self);

/**
 * @brief returns true if the node the root of the tree
 *
 * @param  self the binary tree
 * @return      true iff the node is the root
 */
bool binary_tree_is_root(binary_tree *self);

/**
 * @brief returns height of node in tree. Height is a maximum path length to
 * descendant
 *
 * @param  self the binary tree
 * @return      the height of the node in the tree
 */
int binary_tree_height(binary_tree *self);

/**
 * @brief compute the depth of a node. The depth is the path length from node to
 * root
 *
 * @param  self the binary tree
 * @return      the path length to root of tree
 */
int binary_tree_depth(binary_tree *self);

// Getters

/**
 * @brief returns a representation the subtree rooted at this node
 *
 * @param  self the binary tree
 * @param  str  pointer to the array of chars representing the nodes of subtree
 * @return      string representing the subtree
 */
char *binary_tree_get_string(binary_tree *self, char *str);

/**
 * @brief get left subtree of current node
 *
 * @param  self the binary tree
 * @return      the left subtree of this node
 */
binary_tree *binary_tree_get_left(binary_tree *self);

/**
 * @brief get right subtree of current node
 *
 * @param  self the binary tree
 * @return      the right subtree of this node
 */
binary_tree *binary_tree_get_right(binary_tree *self);

/**
 * @brief get reference to parent of this node
 *
 * @param  self the binary tree
 * @return      reference to parent of this node
 */
binary_tree *binary_tree_get_parent(binary_tree *self);

/**
 * @brief get reference to root of the tree
 *
 * @param  self the binary tree
 * @return      the root of the tree
 */
binary_tree *binary_tree_get_root(binary_tree *self);

#endif //__BINARY_TREE_H__
