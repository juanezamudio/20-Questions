#ifndef __ANIMAL_GAME_H__
#define __ANIMAL_GAME_H__

#include "binary_tree_io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * start the game and user interface...
 *
 * @param file [description]
 * @param file [description]
 */
void play_game(FILE *input, FILE *output);

/**
 * [play_round description]
 * @param AnimalTree [description]
 */
binary_tree *play_round(binary_tree *AnimalTree);

/**
 * returns if a given answer is affirmative by checking first character
 * @param  answer the string given
 * @return        true if affirmative, false otherwise
 */
bool affirmative(char *answer);

#endif
