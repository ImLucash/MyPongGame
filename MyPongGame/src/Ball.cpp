#include "Ball.h"
#include <iostream>
#include "raymath.h"



Ball::Ball(int screenHeight, int screenWidth)
{
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;

	this->ballDisplaySpeed = 1;
	this->ballRadius = 10;
	this->ballPositionY = screenHeight / 2;
	this->ballPositionX = screenWidth / 2;
	this->ballSpeed = 1;
	this->ballMoveX = 350;
	this->ballMoveY = 250;
	this->collisionNumber = 0;
}

void Ball::Draw()
{
	DrawCircle(ballPositionX, ballPositionY, ballRadius, BLUE);
}

void Ball::CollisionCheck(Paddle& lPad, Paddle& rPad)
{
	//CHECK LEFT PADDLE COLLISION
	if (CheckCollisionCircleRec({ ballPositionX,ballPositionY }, ballRadius, lPad.overallSize))
	{

		if (ballMoveX < 0)
		{
			ballMoveX *= -1;
			collisionNumber += 1;
			TraceLog(LOG_INFO, ("COLLISION: " + std::to_string(collisionNumber)).c_str());
			if (collisionNumber > 3)
			{
				ballSpeed += 0.1f;
				ballDisplaySpeed += 1;
				collisionNumber = 0;
				TraceLog(LOG_INFO, ("COLLISION RESET TO: " + std::to_string(collisionNumber)).c_str());
				TraceLog(LOG_INFO, ("MOVEMENT INCREASED TO: " + std::to_string(ballSpeed)).c_str());
			}
		}
	}
	//END CHECK LEFT PADDLE COLLISION

	//CHECK RIGHT PADDLE COLLISION
	if (CheckCollisionCircleRec({ ballPositionX,ballPositionY }, ballRadius, rPad.overallSize))
	{
		if (ballMoveX > 0)
		{
			ballMoveX *= -1;
			collisionNumber += 1;
			TraceLog(LOG_INFO, ("COLLISION: " + std::to_string(collisionNumber)).c_str());
			if (collisionNumber > 3)
			{
				ballSpeed += 0.1f;
				ballDisplaySpeed += 1;
				collisionNumber = 0;
				TraceLog(LOG_INFO, ("COLLISION RESET TO: " + std::to_string(collisionNumber)).c_str());
				TraceLog(LOG_INFO, ("MOVEMENT INCREASED TO: " + std::to_string(ballSpeed)).c_str());
			}
		}

	}
	//END CHECK RIGHT PADDLE COLLISION
};


void Ball::Movement(Score& score)
{
	//BALL MOVEMENT
	ballPositionX += ballMoveX * ballSpeed * GetFrameTime();
	ballPositionY += ballMoveY * ballSpeed * GetFrameTime();



	//LEFT PADDLE WIN
	if (ballPositionX > screenWidth - ballRadius)
	{
		ballPositionX = screenWidth / 2;
		ballPositionY = screenHeight / 2;
		score.ScoreUpdate(LeftSide);
		ballSpeed = 1;
		ballDisplaySpeed = 1;
		collisionNumber = 0;
		ballMoveX *= -1;
	}
	

	//TOP OF SCREEN
	if (ballPositionY > screenHeight - ballRadius)
	{
		ballMoveY *= -1;
	}

	//RIGHT PADDLE WIN
	if (ballPositionX < 0 + ballRadius)
	{
		ballPositionX = screenWidth / 2;
		ballPositionY = screenHeight / 2;
		score.ScoreUpdate(RightSide);
		ballSpeed = 1;
		ballDisplaySpeed = 1;
		collisionNumber = 0;
		ballMoveX *= -1;
	}


	//SCREEN BOTTOM
	if (ballPositionY < 0 + ballRadius)
	{
		ballMoveY *= -1;
	}


}