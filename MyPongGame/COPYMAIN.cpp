//#include <raylib.h>
//#include "Paddle.h"
//#include <iostream>
//
//static const int s_ScreenWidth = 1000;
//static const int s_ScreenHeight = 500;
//
////TODO
////Paddle Constants
//static const float paddleWidth = 20;
//static const float paddleHeight = 100;
//const float paddleSpeed = 250;
//
////Left Paddle
//float leftPaddlePosY = s_ScreenHeight / 2;
//float leftPaddlePosX = 20;
//
//float leftPaddleSide = leftPaddlePosX + (paddleWidth / 2);
//
//
////Right Paddle
//float rightPaddlePosY = s_ScreenHeight / 2;
//float rightPaddlePosX = s_ScreenWidth - 20 - paddleWidth;
//
////INITIALIZE PADDLE PLAYER 1
////INITIALIZE PADDLE PLAYER 2
//
////INITIALIZE BALL SIZE
////INITIALIZE BALL SPEED
////INITIALIZE BALL SHAPE
//const float ballRadius = 10;
//float ballPositionX = s_ScreenWidth / 2;
//float ballPositionY = s_ScreenHeight / 2;
//float ballSpeed = 80;
//float ballMoveX = 250;
//float ballMoveY = 250;
//
//int leftScore = 0;
//int rightScore = 0;
//
//
//
//struct Paddles
//{
//	Rectangle position;
//	Vector2 velocity;
//};
//
//struct Ball
//{
//	Vector2 centrePosition;
//	float ballRad;
//	Vector2 velocity;
//};
//
//int main()
//{
//	//TODO
//	//Initialize Pa
//	// Initialize the window
//	InitWindow(s_ScreenWidth, s_ScreenHeight, "Raylib Game Template");
//
//	// Set the game to run at 60 fps
//	SetTargetFPS(60);
//
//	Paddles leftPaddle = { {leftPaddlePosX,leftPaddlePosY,paddleWidth,paddleHeight}, {leftPaddlePosX, leftPaddlePosY} };
//	Paddles rightPaddle = { {rightPaddlePosX,rightPaddlePosY,paddleWidth,paddleHeight}, {rightPaddlePosX, rightPaddlePosY} };
//	Ball ball = { {ballPositionX, ballPositionY}, {ballRadius}, {ballMoveX, ballMoveY} };
//
//	// Keep the game running until the window close button or the escape key is pressed 
//	while (!WindowShouldClose())
//	{
//		ball.centrePosition.x += ballMoveX * GetFrameTime();
//		ball.centrePosition.y += ballMoveY * GetFrameTime();
//
//
//		//ballPositionX += ballMoveX * GetFrameTime();
//		//ballPositionY += ballMoveY * GetFrameTime();
//		// Update any variables here before drawing
//
//		//LEFT PADDLE KEY PRESS MOVEMENT
//		if (IsKeyDown(KEY_W) && leftPaddle.position.y > 0)
//		{
//			leftPaddle.position.y -= paddleSpeed * GetFrameTime();
//			//leftPaddlePosY -= paddleSpeed * GetFrameTime();
//		}
//		if (IsKeyDown(KEY_S) && leftPaddle.position.y < s_ScreenHeight - paddleHeight)
//		{
//			leftPaddle.position.y += paddleSpeed * GetFrameTime();
//			//leftPaddlePosY += paddleSpeed * GetFrameTime();
//		}
//		//RIGHT PADDLE KEY PRESS MOVEMENT
//		if (IsKeyDown(KEY_UP) && rightPaddle.position.y > 0)
//		{
//			rightPaddle.position.y -= paddleSpeed * GetFrameTime();
//			//rightPaddlePosY -= paddleSpeed * GetFrameTime();
//		}
//		if (IsKeyDown(KEY_DOWN) && rightPaddle.position.y < s_ScreenHeight - paddleHeight)
//		{
//			rightPaddle.position.y += paddleSpeed * GetFrameTime();
//			//rightPaddlePosY += paddleSpeed * GetFrameTime();
//		}
//
//		//BALL CHECK COLLISION TO END OF MAP
//		if (ball.centrePosition.x > s_ScreenWidth - ball.ballRad)
//		{
//			ballMoveX *= -1;
//		}
//		if (ball.centrePosition.y > s_ScreenHeight - ball.ballRad)
//		{
//			ballMoveY *= -1;
//		}
//		if (ball.centrePosition.x < ball.ballRad)
//		{
//			leftScore++;
//			ball.centrePosition.x = ballPositionX;
//		}
//		if (ball.centrePosition.y < ball.ballRad)
//		{
//			ballMoveY *= -1;
//		}
//
//	
//		//BALL COLLISION TO LEFT PADDLE
//		
//		if (CheckCollisionCircleRec(ball.centrePosition, ball.ballRad, leftPaddle.position))
//		{
//			ballMoveX *= -1;
//		};
//		if (CheckCollisionCircleRec(ball.centrePosition, ball.ballRad, rightPaddle.position))
//		{
//			ballMoveX *= -1;
//		};
//
//
//		
//		// Do all of our drawing in here
//		ClearBackground(BLACK);
//
//		BeginDrawing();
//
//		DrawRectangleRec(leftPaddle.position, RED);
//		DrawRectangleRec(rightPaddle.position, GREEN);
//		//DrawRectangle(rightPaddlePosX, rightPaddlePosY, paddleWidth, paddleHeight, GREEN);
//		DrawCircle(ball.centrePosition.x, ball.centrePosition.y, ball.ballRad, BLUE);
//
//		//DrawText("Hello World!", 50, 50, 24, BLUE);
//		DrawText("P1 - " + leftScore, 50, 50, 24, BLUE);
//
//		EndDrawing();
//	}
//
//	// Close the window
//	CloseWindow();
//
//	return 0;
//}
//
//void DrawRectangle(int posX, int posY, int width, int height, Color color);