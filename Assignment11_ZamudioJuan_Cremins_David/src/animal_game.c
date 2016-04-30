
#include "animal_game.h"

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
  char *answer;     // current line
  size_t a = 0;     // current line total mem allocation
  ssize_t line = 0; // current line length (ssize_t is a signed size_t)

  char value[MAX_STRING_SIZE];
  binary_tree *root = tree;

  while (!binary_tree_is_leaf(tree)) {
    fprintf(stdout, "%s\n", binary_tree_get_string(root, value));
    // line = getline(&answer, &a, input);

    if (affirmative(answer)) {
      tree = binary_tree_get_right(tree);
    } else {
      tree = binary_tree_get_left(tree);
    }
  }

  fprintf(stdout, "Were you thinking of a %s?\n",
          binary_tree_get_string(tree, value));

  char finalAnswer[line];

  if (affirmative(finalAnswer)) {
    printf("Great!");
    return root;
  } else {
    while (!feof(stdin)) {
      printf("Doh! What was the animal?\n");
      char answer[MAX_STRING_SIZE];
      fscanf(stdin, "%s\n", answer); // CHANGE
      fprintf(stdout, "What question separates %s from %s?\n", answer, value);
      char question[MAX_STRING_SIZE];
      *question = fscanf(stdin, "%s\n", answer);
      printf("What is the correct answer for this animal?\n");
      char correctAnswer[MAX_STRING_SIZE];
      *correctAnswer = fscanf(stdin, "%s\n", answer);

      binary_tree *parent = NULL;

      if (answer[0] != '\0') {
        parent = binary_tree_get_parent(tree);
      }

      binary_tree *newTree = NULL; // placeholder
      // TODO make new tree with the correct branches off of it modeled off
      // of Java
      //
      // AnimalTree newTree = affirmative(correctAnswer) ?
      //     new AnimalTree(question, tree, new AnimalTree(animal)) :
      //     new AnimalTree(question, new AnimalTree(animal), tree);

      if (answer[0] == '\0') {
        return newTree;
      } else {
        if (affirmative(answer)) {
          binary_tree_set_right(tree, newTree);
        } else {
          binary_tree_set_left(tree, newTree);
        }

        return root;
      }
    }
  }
}

bool affirmative(char *answer) { return answer[0] == 'y' || answer[0] == 'Y'; }
