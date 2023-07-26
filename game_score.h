#pragma once

#include <array>
#include <vector>

#include "text_entity.h"

constexpr int LevelClear = 100;
class GameScore {
public:
	
	GameScore();
	~GameScore();

	void enemy_killed(const int score);
	void level_clear();

	void init_digits(SDL_Renderer* renderer);
	void update_score(int score);
	void parse_score(std::vector<int>& scr, int the_score);

	void render_game_score(SDL_Renderer* renderer);
	void render_high_score(SDL_Renderer* renderer);

	// persist high score to disk;
	void write_high_score();
	void read_high_score();

private:
	int current_score;
	int high_score;
	int level_number;
	float level_clear_multiplier;

	std::vector<int> score_digits;
	std::vector<int> high_score_digits;
	std::array<TextEntity, 10> digits;

};

