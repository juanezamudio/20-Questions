#include "binary_tree_io.h"
#include "binary_tree.h"

void binary_tree_write(binary_tree *self, FILE *stream) {
  // use create functions
  //*binary_tree_get_string(binary_tree *self, char *str)
  if (binary_tree_is_empty(self)) {
    // DO NOTHING?
    return;
  }

  if (binary_tree_is_leaf(self)) {
    // go back to parent, look to the right, if no right continue back to parent
    char *str = NULL; // initialize some other way
    str = binary_tree_get_string(self, str);
    fprintf(stream, "A%s", str);
  } else {            // inner node, therefore a question
    char *str = NULL; // initialize some other way
    str = binary_tree_get_string(self, str);
    fprintf(stream, "Q%s", str);
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

  // binary_tree *newTree = binary_tree_create();
  // maybe not setting first element

  char *line = NULL; // current line
  size_t a = 0;      // current line total mem allocation
  ssize_t n = 0;     // current line length (ssize_t is a signed size_t)

  n = getline(&line, &a, stream);
  if (n == -1) {
    return NULL;
  }
  if (line[0] != 'Q' && line[0] != 'A') {
    // free(line);
    // line = NULL;
    return NULL;
  }
  if (line[0] == '\0') {
    // free(line);
    // line = NULL;
    return NULL;
  }
  size_t index = 0;
  if (line[index] == 'Q') {
    index++;
    // char *str = NULL;
    char str[MAX_STRING_SIZE];
    while (line[index] != '\0') {
      str[index - 1] = line[index];
      index++;
    }
    str[index - 1] = '\0';
    binary_tree *newTree = binary_tree_create_s(str);
    // issue here???
    binary_tree_set_left(newTree, binary_tree_create_f(stream));
    binary_tree_set_right(newTree, binary_tree_create_f(stream));
    return newTree; // OKAY HERE?
    // TODO recursion correctly
  } else if (line[index] == 'A') { // at a leaf/answer
    index++;
    // char *str = NULL;
    char str[MAX_STRING_SIZE];
    while (line[index] != '\0') {
      str[index - 1] = line[index];
      index++;
    }
    str[index - 1] = '\0';
    // necessary here?
    return binary_tree_create_s(str); // Does it moo? not QDoes it moo
  }
  // // Free memory allocated by getline
  // free(line);
  // line = NULL;
  // return newTree;
  return NULL;
}
