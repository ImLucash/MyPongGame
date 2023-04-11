#pragma once
#include <raylib.h>



class Paddle
{
public:
	Paddle(Vector2 position, float width, float height, Color color);
	void Draw();
	void Movement(int up, int down, int screenH, int paddleH);
	void Movement();
	Rectangle overallSize;
	Vector2 velocity;
	int paddleSpeed;

private:
	Vector2 position; 
	float width; 
	float height; 
	Color color; 
	int up; 
	int down;

};

