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

// initialize here
binary_tree *new_tree = NULL; // MAYBE DON'T DO THIS

// Constructors
binary_tree *binary_tree_create() {
  if (new_tree == NULL) {

    new_tree = malloc(sizeof(binary_tree));
    new_tree->value[0] = '\0';
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->parent = NULL;
  }
  return new_tree; // maybe lead to errors?
}

binary_tree *binary_tree_create_s(char *str) { // assume null terminated
  assert(strlen(str) <= MAX_STRING_SIZE);
  binary_tree *tree;
  tree = malloc(sizeof(binary_tree));
  // for (int i = 0; i < strlen(str); i++) {
  //   new_tree->value[i] = str[i];
  // }
  strcpy(tree->value, str);
  tree->left = NULL;
  tree->right = NULL;
  tree->parent = NULL;

  return tree;
}

// fix up like above
binary_tree *binary_tree_create_stt(char *str, binary_tree *left,
                                    binary_tree *right) {
  assert(strlen(str) < MAX_STRING_SIZE); // valid?
  if (new_tree == NULL) {
    new_tree = malloc(sizeof(binary_tree));
    for (int i = 0; i < strlen(str); i++) {
      new_tree->value[i] = str[i];
    }
    new_tree->left = left;
    new_tree->right = right;
    new_tree->parent = NULL;
  }
  return new_tree;
}

// Destructor
// This function should be implemented recursively and free nodes in post- order
void binary_tree_destroy(binary_tree *self) {
  if (!(self->left = self->right = NULL)) { // vs. == ****
    binary_tree_destroy(self->left);
    binary_tree_destroy(self->right);
    free(self);
    self = NULL;
  }
}

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
  return ((self->left == self->right) && (self->left == NULL)); // ok?
  // && (self->value[0] == '\0'))
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
// look at piazza note on this function
char *binary_tree_get_string(binary_tree *self, char *str) {
  int i = 0;
  while (self->value[i] != '\0') {
    str[i] = self->value[i];
    i++;
  }
  str[i] = '\0';
  return str;
}

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
