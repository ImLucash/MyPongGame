#pragma once
#include <string>
#include "raylib.h"

enum PlayerSide{LeftSide, RightSide};

class Score
{
public:
	void Draw();
	Score();
	void ScoreUpdate(PlayerSide playerSide);
protected:
int playerLeftScore;
int playerRightScore;
private:
};
