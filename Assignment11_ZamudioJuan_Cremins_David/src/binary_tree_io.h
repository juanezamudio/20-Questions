#ifndef __BINARY_TREE_IO_H__
#define __BINARY_TREE_IO_H__

#include "binary_tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Writes to a data file, storing the binary tree between
 * runs of the program
 * @param self   a pointer to self, the binary tree
 * @param stream the file you are writing to
 */
void binary_tree_write(binary_tree *self, FILE *stream);

/**
 * Reads from a data file, storing the binary tree between
 * runs of the program
 * @param self    a pointer to self, the binary tree
 * @param stream the file you are reading from
 */
void binary_tree_read(binary_tree *self, FILE *stream);

/**
 * [binary_tree_create_f description]
 * @param  stream [description]
 * @return  NULL, if...
 *            1. the input stream does not represent a
 *            pre-order traversal of a binary tree
 *            2.
 *
 */
binary_tree *binary_tree_create_f(FILE *stream);

#endif //__BINARY_TREE_IO_H__
