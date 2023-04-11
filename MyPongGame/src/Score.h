#pragma once
#include <string>
#include "raylib.h"

enum PlayerSide { LeftSide, RightSide };

class Score
{
public:
	void Draw(int baller);
	Score();
	void ScoreUpdate(PlayerSide playerSide);
	int playerLeftScore;
	int playerRightScore;

protected:

private:

};
