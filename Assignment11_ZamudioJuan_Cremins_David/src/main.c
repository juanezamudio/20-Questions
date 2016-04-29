// TODO: Add Javadoc style header

#include "binary_tree.h"
#include "binary_tree_io.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// TODO: You will probably need to add more includes...

// Program entry point
int main(int argc, char *argv[]) {

  // TODO: Add the game...
  if (argc != 3) {
    printf("Expected 2 command line arguments, but got %d!\n", argc - 1);
    exit(EXIT_FAILURE);
  }

  // Step 1: open files
  FILE *input = fopen(argv[1], "r"); // Open in read mode
  if (input == NULL) {
    printf("Could not open file %s!\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  FILE *output = fopen(argv[2], "w"); // Open in write mode
  if (output == NULL) {
    printf("Could not open file %s!\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  //  Step 3: check for error in file stream
  // if (!feof(input)) {
  //   fprintf(stderr, "Error reading file %s!\n", argv[1]);
  //   exit(EXIT_FAILURE);
  // }

  // Step 4: Close files

  binary_tree *created = binary_tree_create_f(input);
  binary_tree *left = binary_tree_get_left(created);
  if (left == NULL) {
    fprintf(stdout, "null in main\n");
  }
  char helpStr[MAX_STRING_SIZE];
  fprintf(stdout, "%s in main\n", binary_tree_get_string(left, helpStr));
  assert(binary_tree_get_left(created) != NULL);
  binary_tree_write(created, output);

  fclose(stdout);
  fclose(output); // here or above?
  fclose(input);

  return EXIT_SUCCESS;
}
