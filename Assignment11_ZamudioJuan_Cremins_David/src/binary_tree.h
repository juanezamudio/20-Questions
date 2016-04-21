/**
 * TODO: Add Javadocs
 */

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// TODO: Any additional includes that you need.

// TODO: Add Javadoc comments for each of the functions below. See the header
// file in assingment 10 for an example of how the functions should be
// commented. All of the functions declared below have a corresponing method
// in Bailey's BinaryTree class. If you have trouble mathching functions in
// this file to methods in Bailey's class, please let us know.

#define MAX_STRING_SIZE 1000

typedef struct binary_tree binary_tree;

// Constructors
binary_tree* binary_tree_create();
binary_tree* binary_tree_create_s(char* str);
binary_tree* binary_tree_create_stt(char* str, binary_tree* left, binary_tree* right);

// Destructor
void binary_tree_destroy(binary_tree* self);

// Setters
void binary_tree_set_left(binary_tree* self, binary_tree* left);
void binary_tree_set_right(binary_tree* self, binary_tree* right);

// Queries
bool binary_tree_is_empty(binary_tree* self);
bool binary_tree_is_leaf(binary_tree* self);
bool binary_tree_is_left(binary_tree* self);
bool binary_tree_is_right(binary_tree* self);
bool binary_tree_is_root(binary_tree* self);
int binary_tree_height(binary_tree* self);
int binary_tree_depth(binary_tree* self);

// Getters
char* binary_tree_get_string(binary_tree* self, char* str);
binary_tree* binary_tree_get_left(binary_tree* self);
binary_tree* binary_tree_get_right(binary_tree* self);
binary_tree* binary_tree_get_parent(binary_tree* self);
binary_tree* binary_tree_get_root(binary_tree* self);

#endif//__BINARY_TREE_H__
