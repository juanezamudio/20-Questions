#include "binary_tree_io.h"
#include "binary_tree.h"

void binary_tree_write(binary_tree *self, FILE *stream) {
  if (binary_tree_is_empty(self)) {
    return;
  }

  if (binary_tree_is_leaf(self)) {
    fprintf(stream, "leaf");
    // go back to parent, look to the right, if no right continue back to parent
    char str[MAX_STRING_SIZE];
    char *result = binary_tree_get_string(self, str);

    fprintf(stream, "A%s\n", result);
  } else { // inner node, therefore a question
    char str[MAX_STRING_SIZE];
    char *result = binary_tree_get_string(self, str);
    fprintf(stream, "Q%s\n", result);
    // not printing out these children, though at least questions exist!
    binary_tree_write(binary_tree_get_left(self), stream);
    binary_tree_write(binary_tree_get_right(self), stream);
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

  // necessary if just going to be overwritten?
  binary_tree *newTree = binary_tree_create();

  char *line = NULL;
  size_t a = 0;  // current line total mem allocation
  ssize_t n = 0; // current line length (ssize_t is a signed size_t)

  n = getline(&line, &a, stream);

  fprintf(stdout, "n=%d\n", n); // helper statement
  if (n == -1) {
    fprintf(stdout, "fileProblem\n");
    return newTree;
  }
  if (line[0] != 'Q' && line[0] != 'A') {
    return NULL;
  }
  if (line[0] == '\0') {
    return NULL;
  }
  size_t index = 0;
  if (line[index] == 'Q') { // can redo all this w/ strcopy function later
    index++;
    char str[MAX_STRING_SIZE];
    while (line[index] != '\0') {
      str[index - 1] = line[index];
      index++;
    }
    str[index - 1] = '\0';

    newTree = binary_tree_create_s(str); // not str

    // helper statements
    fprintf(stdout, "getting to recursion\n");
    char helpStr[MAX_STRING_SIZE];
    fprintf(stdout, "%s\n", binary_tree_get_string(newTree, helpStr));

    // recursion
    binary_tree_set_left(newTree, binary_tree_create_f(stream));
    binary_tree_set_right(newTree, binary_tree_create_f(stream));

  } else if (line[index] == 'A') { // at a leaf/answer
    index++;
    char str[MAX_STRING_SIZE];
    while (line[index] != '\0') {
      str[index - 1] = line[index];
      index++;
    }
    str[index - 1] = '\0';
    return binary_tree_create_s(str); // base case
  }
  fprintf(stdout, "finishing\n");
  return newTree; // necessary here
}
