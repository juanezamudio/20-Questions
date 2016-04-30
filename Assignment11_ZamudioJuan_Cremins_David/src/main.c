
/**
 *  TODO: Add Javadoc style header
 * @author...
 */
// TODO check for memory leaks on lab computers

#include "animal_game.h"
#include "binary_tree.h"
#include "binary_tree_io.h"
#include <stdio.h>
#include <stdlib.h>

// Program entry point
int main(int argc, char *argv[]) {

  // command line argument file parsing
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

  // TODO find out if needed/why failing
  // Step 3: check for error in file stream
  // if (!feof(input)) {
  //   fprintf(stderr, "Error reading file %s!\n", argv[1]);
  //   exit(EXIT_FAILURE);
  // }

  // testing binary_tree_io.h functions
  binary_tree *created = binary_tree_create_f(input);
  binary_tree_write(created, output);

  // play game!
  play_game(input, output);

  // Step 4: Close files
  fclose(output);
  fclose(input);

  return EXIT_SUCCESS;
}
