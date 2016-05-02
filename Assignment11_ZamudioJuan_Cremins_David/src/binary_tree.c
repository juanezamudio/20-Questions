/**
 * C class that takes care of the functions needed for implementation of a
 * binary tree (create, getters, setters, queries) that will be used as the
 * animal tree game
 *
 * @author Juan Zamudio
 * @author David Cremins
 *
 * @date May 1, 2016
 *
 */
#include "binary_tree.h"
#include <assert.h>
#include <string.h>

// provided struct
struct binary_tree {
  char value[MAX_STRING_SIZE];
  binary_tree *left;
  binary_tree *right;
  binary_tree *parent;
};

// initialize here
binary_tree *new_tree = NULL; // MAYBE DON'T DO THIS

// Constructors

/**
 * @brief creates an empty binary tree
 *
 * @return an empty tree node
 */
binary_tree *binary_tree_create() {
  if (new_tree == NULL) {

    new_tree = malloc(sizeof(binary_tree));
    new_tree->value[0] = '\0';
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->parent = NULL;
  }
  return new_tree;
}

/**
 * @brief Constructs a tree node with no children.  Value of the node
 * and subtrees are provided by the user
 *
 * @param str A non-null value to be referenced by node
 */
binary_tree *binary_tree_create_s(char *str) {
  assert(strlen(str) <= MAX_STRING_SIZE);
  binary_tree *tree;
  tree = malloc(sizeof(binary_tree));
  strcpy(tree->value, str);
  tree->left = NULL;
  tree->right = NULL;
  tree->parent = NULL;

  return tree;
}

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
                                    binary_tree *right) {
  assert(strlen(str) < MAX_STRING_SIZE);
  binary_tree *tree;
  tree = malloc(sizeof(binary_tree));
  strcpy(tree->value, str);
  tree->left = left;
  tree->right = right;
  tree->parent = NULL;

  return tree;
}

// Destructor
// implemented recursively to free nodes in post- order

/**
 * @brief deconstructs the tree
 *
 * @param self the binary tree
 */
void binary_tree_destroy(binary_tree *self) {
  if (!(self->left == self->right) && (self->left == NULL)) {
    binary_tree_destroy(self->left);
    binary_tree_destroy(self->right);
  }
  free(self);
  self = NULL;
}

// Setters
// maintains parent pointers properly

/**
 * @brief Update the left subtree of this node.  Parent of the left subtree is
 * updated consistently.  Existing subtree is detached
 *
 * @param self the binary tree
 * @param left The root of the new left subtree
 */
void binary_tree_set_left(binary_tree *self, binary_tree *left) {
  self->left = left;
  self->left->parent = self;
}

/**
 * @brief Update the right subtree of this node.  Parent of the right subtree is
 * updated consistently.  Existing subtree is detached
 *
 * @param self the binary tree
 * @param right The root of the new right subtree
 */
void binary_tree_set_right(binary_tree *self, binary_tree *right) {
  self->right = right;
  self->right->parent = self;
}

// Queries

/**
 * @brief returns true if the tree is empty
 *
 * @param  self the binary tree
 * @return      true iff the tree is empty
 */
bool binary_tree_is_empty(binary_tree *self) {
  return ((self->left == self->right) && (self->left == NULL) &&
          (self->value[0] == '\0'));
}

/**
 * @brief returns true if the tree is a leaf
 *
 * @param  self the binary tree
 * @return      true iff the tree is a leaf
 */
bool binary_tree_is_leaf(binary_tree *self) {
  return (self->value[0] != '\0' &&
          ((self->left == self->right) && (self->right == NULL)));
}

/**
 * @brief returns true if the node is a left child of the parent
 *
 * @param  self the binary tree
 * @return      true iff the node is a left child of the parent
 */
bool binary_tree_is_left(binary_tree *self) {
  return (self->parent->left == self);
}

/**
 * @brief returns true if the node is a right child of the parent
 *
 * @param  self the binary tree
 * @return      true iff the node is a right child of the parent
 */
bool binary_tree_is_right(binary_tree *self) {
  return (self->parent->right == self);
}

/**
 * @brief returns true if the node the root of the tree
 *
 * @param  self the binary tree
 * @return      true iff the node is the root
 */
bool binary_tree_is_root(binary_tree *self) { return (self->parent == NULL); }

/**
 * @brief returns height of node in tree. Height is a maximum path length to
 * descendant
 *
 * @param  self the binary tree
 * @return      the height of the node in the tree
 */
int binary_tree_height(binary_tree *self) {
  if ((self->left == self->right) && (self->right == NULL)) {
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

/**
 * @brief compute the depth of a node. The depth is the path length from node to
 * root
 *
 * @param  self the binary tree
 * @return      the path length to root of tree
 */
int binary_tree_depth(binary_tree *self) {
  if (self->parent == NULL) {
    return 0;
  } else {
    return (1 + binary_tree_depth(self->parent));
  }
}

// Getters

/**
 * @brief returns a representation the subtree rooted at this node
 *
 * @param  self the binary tree
 * @param  str  pointer to the array of chars representing the nodes of subtree
 * @return      string representing the subtree
 */
char *binary_tree_get_string(binary_tree *self, char *str) {
  strcpy(str, self->value);
  return str;
}

/**
 * @brief get left subtree of current node
 *
 * @param  self the binary tree
 * @return      the left subtree of this node
 */
binary_tree *binary_tree_get_left(binary_tree *self) { return self->left; }

/**
 * @brief get right subtree of current node
 *
 * @param  self the binary tree
 * @return      the right subtree of this node
 */
binary_tree *binary_tree_get_right(binary_tree *self) { return self->right; }

/**
 * @brief get reference to parent of this node
 *
 * @param  self the binary tree
 * @return      reference to parent of this node
 */
binary_tree *binary_tree_get_parent(binary_tree *self) { return self->parent; }

/**
 * @brief get reference to root of the tree
 *
 * @param  self the binary tree
 * @return      the root of the tree
 */
binary_tree *binary_tree_get_root(binary_tree *self) {
  binary_tree *returnTree = self;
  while (returnTree->parent != NULL) {
    returnTree = returnTree->parent;
  }
  return returnTree;
}
