#include "animal_game.h"
#include <assert.h>

/**
 * start the game and user interface
 *
 * @param file that contains text version of the starting tree
 * @param file to output the text version of the updated tree
 */
void play_game(FILE *input, FILE *output) {

  printf("Welcome to the Animals game!\n\n");
  printf("Shall we play a game?\n");

  binary_tree *animalTree = binary_tree_create_f(input);
  assert(animalTree != NULL);

  // get user input from Terminal
  char answer[MAX_STRING_SIZE];
  fgets(answer, sizeof(answer), stdin);

  while (affirmative(answer)) {
    animalTree = play_round(animalTree);
    printf("Shall we play a game?\n");
    fgets(answer, sizeof(answer), stdin);
  }

  // update the output file with the information learned through games
  binary_tree_write(animalTree, output);
}

/**
 * Given a tree plays a round of the game with the user, updating
 * the tree as necessary
 *
 * @param the current game tree
 */
binary_tree *play_round(binary_tree *tree) {
  assert(tree != NULL);
  char value[MAX_STRING_SIZE];
  binary_tree *root = tree;
  char answer[MAX_STRING_SIZE];

  while (!binary_tree_is_leaf(tree)) {
    fprintf(stdout, "%s", binary_tree_get_string(tree, value));
    fgets(answer, sizeof(answer), stdin);
    if (affirmative(answer)) {
      tree = binary_tree_get_right(tree);
      assert(tree != NULL);
    } else {
      tree = binary_tree_get_left(tree);
      assert(tree != NULL);
    }
  }

  char *expected = binary_tree_get_string(tree, value);
  strtok(expected, "\n"); // formatting helper function
  fprintf(stdout, "Were you thinking of a %s?\n", expected);

  char final_answer[MAX_STRING_SIZE];
  fgets(final_answer, sizeof(final_answer), stdin);

  if (affirmative(final_answer)) { // no need to add anything
    printf("Great!\n\n");
    return root;
  } else {

    char *old_animal = binary_tree_get_string(tree, value);

    printf("Doh! What was the animal?\n");
    char new_animal[MAX_STRING_SIZE];
    fgets(new_animal, sizeof(new_animal), stdin); // store new animal in animal

    strtok(old_animal, "\n");
    strtok(new_animal, "\n");
    fprintf(stdout, "What question separates %s from %s?\n", old_animal,
            new_animal);
    char question[MAX_STRING_SIZE];
    fgets(question, sizeof(question), stdin); // store new question in question

    printf("What is the correct answer for this animal?\n");
    char correct_answer[MAX_STRING_SIZE];
    fgets(correct_answer, sizeof(correct_answer),
          stdin); // store correct answer

    // check for no input
    binary_tree *parent;
    if (new_animal[0] == '\0') {
      return root;
    } else { // store parent
      parent = binary_tree_get_parent(tree);
      assert(parent != NULL);
    }

    binary_tree *old = binary_tree_create_s(old_animal);
    binary_tree *new = binary_tree_create_s(new_animal);

    // set up the new branch correctly
    binary_tree *addition;
    if (affirmative(correct_answer)) {
      addition = binary_tree_create_stt(question, old, new);
    } else {
      addition = binary_tree_create_stt(question, new, old);
    }

    // reset the tree correctly
    if (affirmative(answer)) { // most recently given
      binary_tree_set_right(parent, addition);
    } else {
      binary_tree_set_left(parent, addition);
    }

    return root; // the original updated tree
  }
}

// simple check for the first character of a string answer
bool affirmative(char *answer) { return answer[0] == 'y' || answer[0] == 'Y'; }
