#ifndef __BINARY_TREE_IO_H__
#define __BINARY_TREE_IO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO: Add Javadoc comments for these functions.
void binary_tree_write(binary_tree* self, FILE* stream);
binary_tree* binary_tree_create_f(FILE* stream);

#endif//__BINARY_TREE_IO_H__
