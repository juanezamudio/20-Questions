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
  printf("Welcome to the Animals game!\n");
  printf(\n);
  printf("Shall we play a game?");

  binary_tree animalTree = binary_tree_create_f(&input);

  char *answer;     // current line
  size_t a = 0;     // current line total mem allocation
  ssize_t line = 0; // current line length (ssize_t is a signed size_t)

  line = getline(&answer, &a, input);

  while (affirmative(answer[0])) {
    animalTree = play_round(&input, animalTree);
  }
}

/**
 * [play_round description]
 * @param AnimalTree [description]
 */
binary_tree play_round(FILE *input, binary_tree tree) {
  char *answer;     // current line
  size_t a = 0;     // current line total mem allocation
  ssize_t line = 0; // current line length (ssize_t is a signed size_t)

  char *value;
  binary_tree root = tree;

  while (!binary_tree_is_leaf(tree)) {
    fprintf(stdout, "%s\n", binary_tree_get_string(root, &value));
    line = getline(&answer, &a, input);

    if (affirmative(answer[0]) {
      tree = binary_tree_get_right(tree);
    } else {
      tree = binary_tree_get_left(tree);
    }
  }

  fprintf(stdout, "Were you thinking of a %s?\n",
          binary_tree_get_string(tree, &value));

  char *finalAnswer = line;

  if (affirmative(finalAnswer[0])) {
    printf("Great!");
    return root;
  } else {
    while (!feof(stdin)) {
      printf("Doh! What was the animal?\n");
      char *answer = fscanf(stdin, "%s\n", &answer);
      fprintf(stdout, "What question separates %s from %s?\n", &answer, &value);
      char *question = fscanf(stdin, "%s\n", &answer);
      printf("What is the correct answer for this animal?\n");
      char *correctAnswer = fscanf(stdin, "%s\n", &answer);

      binary_tree parent = NULL;

      if (&answer != NULL) {
        parent = binary_tree_get_parent(tree);
      }

      binary_tree newTree = affirmative(correctAnswer);

      // AnimalTree newTree = affirmative(correctAnswer) ?
      //     new AnimalTree(question, tree, new AnimalTree(animal)) :
      //     new AnimalTree(question, new AnimalTree(animal), tree);
      //     I dont really get what this is trying to do...

      if (&answer = NULL) {
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

bool affirmative(char *answer) { return answer[0] == y; }
