#include "Score.h"

Score::Score()
{
	this->playerLeftScore = 0;
	this->playerRightScore = 0;

}

void Score::ScoreUpdate(PlayerSide playerSide)
{
	//SCORE INCREASE
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
	//END SCORE INCREASE
}

void Score::Draw(int baller)
{
	//TEXT DRAWING ON SCREEN 
	std::string rightInfo = "Right Score: " + std::to_string(playerRightScore);
	std::string leftInfo = "Left Score: " + std::to_string(playerLeftScore);
	std::string ballSpeedInfo = "Ball Speed: " + std::to_string(baller);
	DrawText(leftInfo.c_str(), 10, 10, 30, RED);
	DrawText(rightInfo.c_str(), 700, 10, 30, GREEN);
	DrawText(ballSpeedInfo.c_str(), 400, 10, 30, PINK);
	DrawText("Press SPACE to PAUSE", 400, 480, 20, ORANGE);
	//END TEXT DRAWING ON SCREEN
}
