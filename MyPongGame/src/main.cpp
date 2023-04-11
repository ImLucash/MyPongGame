#include <raylib.h>
#include "Paddle.h"
#include <iostream>
#include <Ball.h>
#include "Score.h"

static const int s_ScreenWidth = 1000;
static const int s_ScreenHeight = 500;

//TODO
//Paddle Constants
static const float paddleWidth = 3;
static const float paddleHeight = 100;
const float paddleSpeed = 250;

//Left Paddle
//float leftPaddlePosY = s_ScreenHeight / 2;
//float leftPaddlePosX = 20;

//float leftPaddleSide = leftPaddlePosX + (paddleWidth / 2);


//Right Paddle
//float rightPaddlePosY = s_ScreenHeight / 2;
//float rightPaddlePosX = s_ScreenWidth - 20 - paddleWidth;


//const float ballRadius = 10;
//float ballPositionX = s_ScreenWidth / 2;
//float ballPositionY = s_ScreenHeight / 2;
//float ballSpeed = 80;
//float ballMoveX = 250;
//float ballMoveY = 250;

//int playerLeftScore = 0;
//int playerRightScore = 0;



//struct Paddles
//{
//	Rectangle position;
//	Vector2 velocity;
//};

//struct Ball
//{
//	
//};

int main()
{
	//TODO
	//Initialize Pa
	// Initialize the window
	InitWindow(s_ScreenWidth, s_ScreenHeight, "Raylib Game Template");

	// Set the game to run at 60 fps
	SetTargetFPS(60);
	Paddle leftPaddle( {20, s_ScreenHeight / 2 }, paddleWidth, paddleHeight, RED);
	Paddle rightPaddle({ s_ScreenWidth - 20 - paddleWidth, s_ScreenHeight / 2 }, paddleWidth, paddleHeight, GREEN);
	Ball ball ( s_ScreenHeight, s_ScreenWidth );
	//ball = Ball(s_ScreenHeight, s_ScreenWidth);
	Score updateScore;

	
	// = { {leftPaddlePosX,leftPaddlePosY,paddleWidth,paddleHeight}, {leftPaddlePosX, leftPaddlePosY} };
	//Paddles leftPaddle = { {leftPaddlePosX,leftPaddlePosY,paddleWidth,paddleHeight}, {leftPaddlePosX, leftPaddlePosY} };
	//Paddles rightPaddle = { {rightPaddlePosX,rightPaddlePosY,paddleWidth,paddleHeight}, {rightPaddlePosX, rightPaddlePosY} };

	// Keep the game running until the window close button or the escape key is pressed 
	while (!WindowShouldClose())
	{
		

		//ball.Draw();

		//ballPositionX += ballMoveX * GetFrameTime();
		//ballPositionY += ballMoveY * GetFrameTime();
		// Update any variables here before drawing

		////LEFT PADDLE KEY PRESS MOVEMENT
		//if (IsKeyDown(KEY_W) && leftPaddle.overallSize.y > 0)
		//{
		//	leftPaddle.overallSize.y -= paddleSpeed * GetFrameTime();
		//	//leftPaddlePosY -= paddleSpeed * GetFrameTime();
		//}
		//if (IsKeyDown(KEY_S) && leftPaddle.overallSize.y < s_ScreenHeight - paddleHeight)
		//{
		//	leftPaddle.overallSize.y += paddleSpeed * GetFrameTime();
		//	//leftPaddlePosY += paddleSpeed * GetFrameTime();
		//}
		//RIGHT PADDLE KEY PRESS MOVEMENT
		//////if (IsKeyDown(KEY_UP) && rightPaddle.position.y > 0)
		//////{
		//////	rightPaddle.position.y -= paddleSpeed * GetFrameTime();
		//////	//rightPaddlePosY -= paddleSpeed * GetFrameTime();
		//////}
		//////if (IsKeyDown(KEY_DOWN) && rightPaddle.position.y < s_ScreenHeight - paddleHeight)
		//////{
		//////	rightPaddle.position.y += paddleSpeed * GetFrameTime();
		//////	//rightPaddlePosY += paddleSpeed * GetFrameTime();
		//////}

		//BALL CHECK COLLISION TO END OF MAP
		

		//if (ballPositionX > s_ScreenWidth - ballRadius)
		//{
		//	ballMoveX *= -1;
		//}
		//if (ballPositionY > s_ScreenHeight - ballRadius)
		//{
		//	ballMoveY *= -1;
		//}
		//if (ballPositionX < ballRadius)
		//{
		//	ballMoveX *= -1;
		//}
		//if (ballPositionY < ballRadius)
		//{
		//	ballMoveY *= -1;
		//}



		//std::cout << leftPaddle.overallSize.x << std::endl;
		

		//BALL COLLISION TO LEFT PADDLE
		// 

		//if (CheckCollisionCircleRec(ball.centrePosition, ball.ballRad, rightPaddle.overallSize))
		//{
		//	ballMoveX *= -1;
		//};
		
		leftPaddle.Movement(KEY_W, KEY_S, s_ScreenHeight, paddleHeight);
		rightPaddle.Movement(KEY_UP, KEY_DOWN, s_ScreenHeight, paddleHeight);
		ball.Movement(updateScore);
		ball.CollisionCheck(leftPaddle, rightPaddle);
		//ball.CollisionCheck(rightPaddle);
	
		
		// Do all of our drawing in here
		ClearBackground(BLACK);

		BeginDrawing();

		leftPaddle.Draw();
		rightPaddle.Draw();
		ball.Draw();
		updateScore.Draw();
		
		


		EndDrawing();
	}

	// Close the window
	CloseWindow();

	return 0;
	}

	//void DrawRectangle(int posX, int posY, int width, int height, Color color);