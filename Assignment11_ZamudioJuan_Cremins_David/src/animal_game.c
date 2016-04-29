// TODO: Use this file for your game logic.
#include "animal_game.h"

/**
 * start the game and user interface
 *
 * System.out.println("Welcome to the Animals game!");
 System.out.println();
 System.out.print("Shall we play a game? ");

 * @param file [description]
 * @param file [description]
 */
void play_game(FILE *input, FILE *output) {
  // TODO use output in this function
  printf("Welcome to the Animals game!\n");
  printf("\n");
  printf("Shall we play a game?");

  binary_tree *animalTree = binary_tree_create_f(input);

  char *answer;     // current line
  size_t a = 0;     // current line total mem allocation
  ssize_t line = 0; // current line length (ssize_t is a signed size_t)

  line = getline(&answer, &a, input);

  while (affirmative(answer)) {
    animalTree = play_round(input, animalTree);
  }
}

/**
 * [play_round description]
 * @param AnimalTree [description]
 */
binary_tree *play_round(FILE *input, binary_tree *tree) {
  char *answer;     // current line
  size_t a = 0;     // current line total mem allocation
  ssize_t line = 0; // current line length (ssize_t is a signed size_t)

  char value[MAX_STRING_SIZE];
  binary_tree *root = tree;

  while (!binary_tree_is_leaf(tree)) {
    fprintf(stdout, "%s\n", binary_tree_get_string(root, value));
    line = getline(&answer, &a, input);

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

bool affirmative(char *answer) { return answer[0] == 'y'; }
