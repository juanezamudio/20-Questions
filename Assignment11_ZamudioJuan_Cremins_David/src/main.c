/**
 * C class that is the main method
 *
 * @author Juan Zamudio
 * @author David Cremins
 *
 * @date May 1, 2016
 */

// TODO check for memory leaks on lab computers

#include "animal_game.h"
#include "binary_tree.h"
#include "binary_tree_io.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Program entry point
int main(int argc, char *argv[]) {

  // command line argument file parsing
  if (argc != 3) {
    printf("Expected 2 command line arguments, but got %d!\n", argc - 1);
    exit(EXIT_FAILURE);
  }

  // open files
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

  // play game!
  play_game(input, output);

  // close files
  fclose(output);
  fclose(input);

  return EXIT_SUCCESS;
}
