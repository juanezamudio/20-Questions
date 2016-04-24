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
 * @param stream the input stream
 */
void binary_tree_write(binary_tree *self, FILE *stream);

/**
 * Creates a binary tree from a data file
 * @param  stream the input stream
 * @return    Binary tree or NULL, if...
 *            1. the input stream does not represent a
 *            pre-order traversal of a binary tree
 *            2. there is a line in the input file
 *            that does not begin with Q or A
 *            3. there is a blank line in the input file
 *            4. Any other unexpected error occurs
 */
binary_tree *binary_tree_create_f(FILE *stream);

#endif //__BINARY_TREE_IO_H__
