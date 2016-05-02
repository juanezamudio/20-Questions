/**
 * Header class that takes care of the functions needed to play the animal game
 * (play game, play round, affirmative)
 *
 * @author Juan Zamudio
 * @author David Cremins
 *
 * @date May 1, 2016
 *
 */
#ifndef __ANIMAL_GAME_H__
#define __ANIMAL_GAME_H__

#include "binary_tree_io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief starts the game and user interface
 *
 * @param input the input file
 * @param output the output file
 */
void play_game(FILE *input, FILE *output);

/**
 * @brief plays a round of the game
 *
 * @param AnimalTree the game tree
 */
binary_tree *play_round(binary_tree *AnimalTree);

/**
 * @brief returns if a given answer is affirmative by checking first character
 *
 * @param  answer the character given
 * @return        true if affirmative ('y' or 'Y'), false otherwise
 */
bool affirmative(char *answer);

#endif
