#include "Score.h"

Score::Score()
{
	this->playerLeftScore = 0;
	this->playerRightScore = 0;

}

void Score::ScoreUpdate(PlayerSide playerSide)
{
	if (playerSide == LeftSide)
	{
		playerLeftScore++;
		TraceLog(LOG_INFO, ("L: " + std::to_string(playerLeftScore)).c_str());
	}
	else
	{
		playerRightScore++;
		TraceLog(LOG_INFO, ("R: " + std::to_string(playerRightScore)).c_str());
	}
}

void Score::Draw()
{
	std::string Info = "Right Score: " + std::to_string(playerRightScore) + " Left Score: " + std::to_string(playerLeftScore);
	DrawText(Info.c_str(), 10, 10, 10, RED);
}
