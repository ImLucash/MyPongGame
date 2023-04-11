#include "Ball.h"
#include <iostream>
#include "raymath.h"



Ball::Ball(int screenHeight, int screenWidth)
{
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;


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

void Ball::CollisionCheck(Paddle& paddle)
{
	if (CheckCollisionCircleRec({ ballPositionX,ballPositionY }, ballRadius, paddle.overallSize))
	{
		//Vector2 dis;
		//dis.x = paddle.overallSize.x - ballPositionX;
		//dis.y = paddle.overallSize.y - ballPositionY;
		//Vector2Normalize(dis);
		//if (dis.y > 0.7f)
		//{
		//	ballMoveY *= -1;
		//	ballPositionY += ballMoveY * ballSpeed * GetFrameTime();
		//}

		//Vector2 RecCenter = { paddle.overallSize.x + paddle.overallSize.width / 2, paddle.overallSize.y + paddle.overallSize.height / 2 };
		//Vector2 BallCenter = { ballPositionX, ballPositionY };
		

		//float angle = atan2f(RecCenter.x - ballPositionX, RecCenter.y - ballPositionY) * RAD2DEG;

		//if (angle > 45 && angle < 135 || angle > -45 && angle < -135)
		//{
		//	ballMoveY *= -1;
		//	ballPositionY += ballMoveY * ballSpeed * GetFrameTime();
		//}
		

		//if (ballPositionY = paddle.overallSize.y + paddle.overallSize.width / 2)

		//TO DO COLLISION SPEED INCREASE AFTER NUMBER OF HITS, MOVE COLLISION NUMBER OUTSIDE OF FUNCTION
		

		if (collisionNumber < 2)
		{
			ballMoveX *= -1;
			collisionNumber += 1;
			std::cout << collisionNumber << std::endl;

		}

		else
		{
		ballMoveX *= -1;
		ballSpeed += 0.5f;
		collisionNumber = 0;
		std::cout << collisionNumber << std::endl;

		}
	


		//ballPositionX += ballMoveX * ballSpeed * GetFrameTime();
		//ballPositionY += ballMoveY * ballSpeed * GetFrameTime();
	};
}

void Ball::Movement(Score& score)
{
	ballPositionX += ballMoveX * ballSpeed * GetFrameTime();
	ballPositionY += ballMoveY * ballSpeed * GetFrameTime();



	//right paddle loss
	if (ballPositionX > screenWidth - ballRadius)
	{
		ballPositionX = screenWidth / 2;
		ballPositionY = screenHeight / 2;
		score.ScoreUpdate(LeftSide);
		ballSpeed = 1;
		collisionNumber = 0;
	}
	//screen top
	if (ballPositionY > screenHeight - ballRadius)
	{
		ballMoveY *= -1;
	}
	//left paddle loss
	if (ballPositionX < 0 + ballRadius)
	{
		ballPositionX = screenWidth / 2;
		ballPositionY = screenHeight / 2;
		score.ScoreUpdate(RightSide);
		ballSpeed = 1;
		collisionNumber = 0;
	}
	//screen bottom
	if (ballPositionY < 0 + ballRadius)
	{
		ballMoveY *= -1;
	}


}