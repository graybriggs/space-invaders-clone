#pragma once

constexpr int LevelClear = 100;
class GameScore {
public:
	
	GameScore();

	void enemy_killed(const int score);
	void level_clear();

private:
	int current_score;
	int level_number;
	float level_clear_multiplier;

};

