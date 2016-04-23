#include "binary_tree.h"
#include <assert.h> // valid?
#include <string.h>

// We have provided you with the binary tree struct. This struct must not be
// changed. You should implement the binary tree functions declared in
// binary_tree.h, and any helper functions you would like in this file.

struct binary_tree {
  char value[MAX_STRING_SIZE];
  binary_tree *left;
  binary_tree *right;
  binary_tree *parent;
};

// Constructors
// TODO malloc in all of the constructors
binary_tree *binary_tree_create() {
  binary_tree *newTree = {NULL, NULL, NULL};
  newTree->value[0] = '\0';
  // newTree->value = NULL; // starts empty?
  malloc(sizeof(newTree));
  // newTree->left = NULL;
  // newTree->right = NULL; // left and right 'this'?
  // newTree->parent = NULL;
  return newTree;
} // don't need ending ; ?

binary_tree *binary_tree_create_s(char *str) {  // assume null terminated{
  assert(strlen(str) < MAX_STRING_SIZE);        // valid?
  binary_tree *newTreeTwo = {NULL, NULL, NULL}; // why only need two?
  malloc(sizeof(newTreeTwo));
  for (int i = 0; i < strlen(str); i++) {
    newTreeTwo->value[i] = str[i];
  }
  return newTreeTwo;
}

binary_tree *binary_tree_create_stt(char *str, binary_tree *left,
                                    binary_tree *right) {
  assert(strlen(str) < MAX_STRING_SIZE);     // valid?
  binary_tree *newTreeThree = {left, right}; // why only need two?
  malloc(sizeof(newTreeThree));
  for (int i = 0; i < strlen(str); i++) {
    newTreeThree->value[i] = str[i];
  }
  return newTreeThree;
}

// Destructor
// This function should be implemented recursively and free nodes in post- order
void binary_tree_destroy(binary_tree *self) {
  free(self);
  self = NULL;
};

// Setters
// The greatest challenge is to maintain the parent pointers properly when
// executing binary_tree_set_left and binary_tree_set_right
void binary_tree_set_left(binary_tree *self, binary_tree *left) {
  if (self->left != NULL) {
    binary_tree_destroy(self->left);
  }
  self->left = left;
  self->left->parent = self;
}
void binary_tree_set_right(binary_tree *self, binary_tree *right) {
  if (self->right != NULL) {
    binary_tree_destroy(self->right);
  }
  self->right = right;
  self->right->parent = self; // right path?
}

// Queries
bool binary_tree_is_empty(binary_tree *self) {
  return ((self->left = self->right = NULL) && (self->value[0] == '\0')); // ok?
}

bool binary_tree_is_leaf(binary_tree *self) {
  return (self->value[0] != '\0' && (self->left = self->right = NULL));
}

bool binary_tree_is_left(binary_tree *self) {
  return (self->parent->left == self); // double equals good?
}

bool binary_tree_is_right(binary_tree *self) {
  return (self->parent->right == self);
}

bool binary_tree_is_root(binary_tree *self) {
  return (self->value[0] != '\0' && self->parent == NULL);
}

int binary_tree_height(binary_tree *self) {
  if ((self->left = self->right = NULL)) {
    return -1;
  } else {
    int rightHeight = (binary_tree_height(self->right) + 1);
    int leftHeight = (binary_tree_height(self->left) + 1);
    if (rightHeight > leftHeight) {
      return rightHeight;
    }
    return leftHeight;
  }
}

int binary_tree_depth(binary_tree *self) {
  if (self->parent == NULL) {
    return 0;
  } else {
    return (1 + binary_tree_depth(self->parent));
  }
}

// Getters
// not sure exactly what this one wants to do
char *binary_tree_get_string(binary_tree *self, char *str);

binary_tree *binary_tree_get_left(binary_tree *self) { return self->left; }

binary_tree *binary_tree_get_right(binary_tree *self) { return self->right; }

binary_tree *binary_tree_get_parent(binary_tree *self) { return self->parent; }

binary_tree *binary_tree_get_root(binary_tree *self) {
  binary_tree *returnTree = self;
  while (returnTree->parent != NULL) {
    returnTree = returnTree->parent;
  }
  return returnTree;
}
