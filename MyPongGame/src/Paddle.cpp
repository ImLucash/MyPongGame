#include "Paddle.h"
#include <iostream>


Paddle::Paddle(Vector2 position, float width, float height, Color color)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->up = up;
	this->down = down;
	this->paddleSpeed = 300;

	this->overallSize = { position.x, position.y, width, height };
	this->velocity = { position.x, position.y };

}

void Paddle::Draw()
{
	DrawRectangleRec(overallSize, color);
}

void Paddle::Movement(int up, int down, int screenH, int paddleH)
{

	if (IsKeyDown(up) && overallSize.y > 0)
	{
		overallSize.y -= paddleSpeed * GetFrameTime();
	}
	if (IsKeyDown(down) && overallSize.y < screenH - paddleH)
	{
		overallSize.y += paddleSpeed * GetFrameTime();
	}
}
