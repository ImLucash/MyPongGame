#pragma once
#include <iostream>
#include <raylib.h>
#include "Paddle.h"
#include "Score.h"


class Ball
{
public:
	int screenHeight;
	int screenWidth;
	Ball(int screenHeight, int screenWidth);
	void Movement(Score& score);
	void Draw();
	void CollisionCheck(Paddle& lPad, Paddle& rPad);
	float ballRadius;
	float ballPositionX;
	float ballPositionY;
	float ballSpeed;
	int ballDisplaySpeed;
	float ballMoveX;
	float ballMoveY;
	int collisionNumber;
	

protected:

private:
	float ballRad;
};

