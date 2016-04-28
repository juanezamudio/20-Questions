// TODO: Add Javadoc style header

#include "binary_tree.h"
#include "binary_tree_io.h"
#include <stdio.h>
#include <stdlib.h>
// TODO: You will probably need to add more includes...

// Program entry point
int main(int argc, char *argv[]) {
  printf("Welcome to the Animals game!\n");

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
  if (input == NULL) {
    printf("Could not open file %s!\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // binary_tree *gameTree = binary_tree_create();
  // binary_tree_write(gameTree, output);

  // Step 3: check for error in file stream
  // if (!feof(input)) {
  //   fprintf(stderr, "Error reading file %s!\n", argv[1]);
  //   exit(EXIT_FAILURE);
  //

  // Step 4: Close files
  fclose(input);
  fclose(output);

  // issue probably in this function
  binary_tree *created = binary_tree_create_f(input);
  binary_tree *gameTree = binary_tree_create_s("ooga"); // testing
  binary_tree_write(created, output);

  return EXIT_SUCCESS;
}
