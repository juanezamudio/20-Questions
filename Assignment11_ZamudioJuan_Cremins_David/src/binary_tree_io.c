#include "binary_tree_io.h"
#include "binary_tree.h"

/**
 * writes a valid binary tree to an output file pre-order
 *
 * @param self    pointer to the binary tree
 * @param stream  file to be written to
 */
void binary_tree_write(binary_tree *self, FILE *stream) {
  if (self == NULL) {
    return;
  }
  if (binary_tree_is_empty(self)) {
    return;
  }
  if (binary_tree_is_leaf(self)) {
    char str[MAX_STRING_SIZE];
    char *result = binary_tree_get_string(self, str);
    fprintf(stream, "A%s", result);
  } else { // inner node, therefore a question
    char str[MAX_STRING_SIZE];
    char *result = binary_tree_get_string(self, str);
    fprintf(stream, "Q%s", result);

    // recursion
    binary_tree *left = binary_tree_get_left(self);
    binary_tree *right = binary_tree_get_right(self);
    binary_tree_write(left, stream);
    binary_tree_write(right, stream);
  }
}

/**
 * Creates a binary tree from a data file
 * @param  stream the input stream
 * @return    Binary tree or NULL, if...
 *            1. the input stream does not represent a
 *            pre-order traversal of a binary tree
 *            4. Any other unexpected error occurs
 */
binary_tree *binary_tree_create_f(FILE *stream) {

  binary_tree *newTree = binary_tree_create();

  char *line = NULL;
  size_t a = 0;  // current line total mem allocation
  ssize_t n = 0; // current line length

  n = getline(&line, &a, stream);
  if (n == -1) {
    return NULL; // newTree?
  }
  if (line[0] != 'Q' && line[0] != 'A') {
    return NULL;
  }
  if (line[0] == '\0') {
    return NULL;
  }
  size_t index = 0;
  if (line[index] == 'Q') { // not at a leaf
    index++;
    char str[MAX_STRING_SIZE];
    while (line[index] != '\0') {
      str[index - 1] = line[index];
      index++;
    }
    str[index - 1] = '\0';

    newTree = binary_tree_create_s(str);

    // recursion
    // maybe use the other creation function and use asserts to find problems
    // TODO enable it to work when two questions go in a row
    binary_tree *left = binary_tree_create_f(stream);
    binary_tree *right = binary_tree_create_f(stream);
    binary_tree_set_left(newTree, left);
    binary_tree_set_right(newTree, right);

  } else if (line[index] == 'A') { // at a leaf/answer
    index++;
    char str[MAX_STRING_SIZE];
    while (line[index] != '\0') {
      str[index - 1] = line[index];
      index++;
    }
    str[index - 1] = '\0';

    binary_tree *leaf = binary_tree_create_s(str);
    return leaf; // base case
  }
  return newTree;
}
