// TODO: Use this file for your game logic.
#ifndef __ANIMAL_GAME_H__
#define __ANIMAL_GAME_H__

#include "binary_tree_io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * start the game and user interface
 *
 * System.out.println("Welcome to the Animals game!");
 System.out.println();
 System.out.print("Shall we play a game? ");

 * @param file [description]
 * @param file [description]
 */
void play_game(FILE *input, FILE *output);
// ask to play a game
// start play_round() in a while loop
// when that function done ask again
// if "yes" again stay in the while loop
// else exit the game and write finished tree to output file

/**
 * [play_round description]
 * @param AnimalTree [description]
 */
binary_tree *play_round(FILE *input, binary_tree *AnimalTree);

bool affirmative(char *answer);
// private static boolean affirmative(String answer){
// return answer.equals("y");

#endif
