#include "binary_tree.h"

// We have provided you with the binary tree struct. This struct must not be
// changed. You should implement the binary tree functions declared in
// binary_tree.h, and any helper functions you would like in this file.

struct binary_tree
{
    char value[MAX_STRING_SIZE];
    binary_tree* left;
    binary_tree* right;
    binary_tree* parent;
};
