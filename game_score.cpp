
#include "game_score.h"

//#include <iostream>

//constexpr int GameScore::LevelClear = 100;

GameScore::GameScore() :
	current_score(0),
	level_number(1),
	level_clear_multiplier(1.0)
{}

void GameScore::enemy_killed(const int score) {
   	current_score += score;
	//std::cout << current_score << std::endl;
}

void GameScore::level_clear() {

	// multiplier starts at 1.0 and increases by 0.1 each clear screen.
	current_score += LevelClear * level_clear_multiplier;

	level_number++;
	level_clear_multiplier += 0.1f;
}
