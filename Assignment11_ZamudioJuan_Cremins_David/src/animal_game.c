
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
  // char *answer;     // current line
  // size_t a = 0;     // current line total mem allocation
  // ssize_t line = 0; // current line length (ssize_t is a signed size_t)

  char value[MAX_STRING_SIZE]; // for use :P
  binary_tree *root = tree;

  while (!binary_tree_is_leaf(tree)) {
    fprintf(stdout, "%s\n", binary_tree_get_string(root, value));
    // line = getline(&answer, &a, input);
    fgets(value, sizeof(value), stdin);
    if (affirmative(value)) {
      tree = binary_tree_get_right(tree);
    } else {
      tree = binary_tree_get_left(tree);
    }
  }

  fprintf(stdout, "Were you thinking of a %s?\n",
          binary_tree_get_string(tree, value));

  char final_answer[MAX_STRING_SIZE];
  fgets(final_answer, sizeof(final_answer), stdin);

  if (affirmative(final_answer)) {
    printf("Great!");
    return root;
  } else {
    //  while (!feof(stdin)) {
    // fscanf(stdin, "%s\n", answer); // CHANGE
    //*question = fscanf(stdin, "%s\n", answer);
    //*correctAnswer = fscanf(stdin, "%s\n", answer);

    // char old_animal[MAX_STRING_SIZE]; // something like that
    char *old_animal = binary_tree_get_string(tree, value);

    printf("Doh! What was the animal?\n");
    char new_animal[MAX_STRING_SIZE];
    fgets(new_animal, sizeof(new_animal), stdin); // store new animal in animal

    fprintf(stdout, "What question separates %s from %s?\n", old_animal,
            new_animal);
    char question[MAX_STRING_SIZE];
    fgets(question, sizeof(question), stdin); // store new question in question

    printf("What is the correct answer for this animal?\n");
    char correct_answer[MAX_STRING_SIZE];
    fgets(correct_answer, sizeof(correct_answer),
          stdin); // store correct answer

    // binary_tree *parent = NULL;
    // if (animal[0] != '\0') {
    //   parent = binary_tree_get_parent(tree);
    // } // what does this accomplish?

    // binary_tree *newTree = NULL; // placeholder

    // AnimalTree newTree = affirmative(correctAnswer) ?
    //     new AnimalTree(question, tree, new AnimalTree(animal)) :
    //     new AnimalTree(question, new AnimalTree(animal), tree);
    // TODO - this necessary? if (animal[0] == '\0') {
    //   return newTree;
    // }

    // make old_animal and new_animal their own trees left and right based on
    // answers
    //
    // TODO put new_animal in left and old_animal in right always??
    binary_tree *left = binary_tree_create_s(old_animal);
    binary_tree *right = binary_tree_create_s(new_animal);
    binary_tree *addition = binary_tree_create_stt(question, left, right);

    if (affirmative(value)) { // the answer most recently given
      binary_tree_set_right(tree, addition);
      // guessing directions right now
    } else {
      binary_tree_set_left(tree, addition);
    }

    //
    // if (affirmative(correct_answer)) {
    //   binary_tree_set_right(tree, newTree);
    // } else {
    //   binary_tree_set_left(tree, newTree);
    // }

    return root;
  }
}

bool affirmative(char *answer) { return answer[0] == 'y' || answer[0] == 'Y'; }
