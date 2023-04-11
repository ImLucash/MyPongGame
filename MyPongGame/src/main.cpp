#include <raylib.h>
#include "Paddle.h"
#include <iostream>
#include <Ball.h>
#include "Score.h"

//SCREEN HEIGHT AND WIDTH CONSTANT
static const int s_ScreenWidth = 1000;
static const int s_ScreenHeight = 500;

//PADDLE HEIGHT AND WIDTH AND SPEED CONSTANT
static const float paddleWidth = 3;
static const float paddleHeight = 100;
const float paddleSpeed = 250;
bool inMenu = true;
bool pausedGame = false;
bool mainGamePlay = false;
void MainMenu(Paddle& leftPaddle, Paddle& rightPaddle, Ball& ball, Score& updateScore);
void PauseMenu(Paddle& leftPaddle, Paddle& rightPaddle, Ball& ball, Score& updateScore);
void EndGame(Score& updateScore);


int main()
{
	//SET SCREEN WINDOW TO HEIGHT AND WIDTH
	InitWindow(s_ScreenWidth, s_ScreenHeight, "Raylib Game Template");

	//SET FRAMES TO 60 FPS
	SetTargetFPS(60);

	//INSTATIATING THE GAME ELEMENTS 
	Paddle leftPaddle({ 20, s_ScreenHeight / 2 }, paddleWidth, paddleHeight, RED);
	Paddle rightPaddle({ s_ScreenWidth - 20 - paddleWidth, s_ScreenHeight / 2 }, paddleWidth, paddleHeight, GREEN);
	Ball ball(s_ScreenHeight, s_ScreenWidth);
	Score updateScore;


	// PLAY MAIN GAME AND CONTINUE RUNNING 
	while (!WindowShouldClose())
	{
		//BEGIN WITH MAIN MENU
		if (inMenu == true)
		{
			MainMenu(leftPaddle, rightPaddle, ball, updateScore);
		}

		//WILL PAUSE THE GAME AND GO TO PAUSE FUNTION
		if (IsKeyPressed(KEY_SPACE))
		{
			pausedGame = true;
			mainGamePlay = false;
			PauseMenu(leftPaddle, rightPaddle, ball, updateScore);
		}

		//MAIN CODE RUNNING GAME LOOP
		if (pausedGame == false)
		{
			//CHECK OBJECTS MOVEMENT
			leftPaddle.Movement(KEY_W, KEY_S, s_ScreenHeight, paddleHeight);
			rightPaddle.Movement(KEY_UP, KEY_DOWN, s_ScreenHeight, paddleHeight);
			ball.Movement(updateScore);

			//CHECK BALL COLLISION WITH PADDLES
			ball.CollisionCheck(leftPaddle, rightPaddle);

			//CLEAR SCREEN TO BLACK EACH FRAME
			ClearBackground(BLACK);

			//BEGIN DRAW
			BeginDrawing();

			//DRAW OBJECTS
			leftPaddle.Draw();
			rightPaddle.Draw();
			ball.Draw();
			updateScore.Draw(ball.ballDisplaySpeed);

			if (updateScore.playerLeftScore >= 2 || updateScore.playerRightScore >= 2)
			{
				ClearBackground(BLACK);
				mainGamePlay = false;
				EndGame(updateScore);
			}


			//STOP DRAWING
			EndDrawing();
		}
	}

	//CLOSE GAME
	CloseWindow();

	return 0;
}

void MainMenu(Paddle& leftPaddle, Paddle& rightPaddle, Ball& ball, Score& updateScore)
{

	bool entry = true;
	while (inMenu == true)
	{
		ClearBackground(BLACK);
		BeginDrawing();



		DrawText("Lucas Wittingslow C++ PONG ", s_ScreenWidth / 2, s_ScreenHeight / 2, 30, GREEN);
		DrawText("MAIN MENU", s_ScreenWidth / 2 - 380, s_ScreenHeight / 2 - 50, 50, WHITE);
		DrawText("Press SPACE to PLAY", s_ScreenWidth / 2 - 380, s_ScreenHeight / 2 + 50, 25, WHITE);

		if (IsKeyPressed(KEY_SPACE) && !entry)
		{
			leftPaddle.overallSize.y = GetScreenHeight() / 2;
			rightPaddle.overallSize.y = GetScreenHeight() / 2;
			ball.ballPositionX = GetScreenWidth() / 2;
			ball.ballPositionY = GetScreenHeight() / 2;
			updateScore.playerLeftScore = 0;
			updateScore.playerRightScore = 0;
			ball.collisionNumber = 0;
			ball.ballSpeed = 1;
			ball.ballDisplaySpeed = 1;
			inMenu = false;
			mainGamePlay = true;

		}
		EndDrawing();
		entry = false;
	}
}

void PauseMenu(Paddle& leftPaddle, Paddle& rightPaddle, Ball& ball, Score& updateScore)
{
	bool entry = true;
	
	while (pausedGame == true)
	{
		ClearBackground(BLACK);
		//REMOVED CLEAR BACKGROUND SO YOU SEE THE PADDLES AND BALL STILL
		//ClearBackground(BLACK);

		BeginDrawing();
		ClearBackground(BLACK);
		leftPaddle.Draw();
		rightPaddle.Draw();
		ball.Draw();
		updateScore.Draw(ball.ballDisplaySpeed);

		//SCREEN TEXT
		DrawText("PAUSED ", s_ScreenWidth / 4, s_ScreenHeight / 2 - 90, 50, DARKGREEN);
		DrawText("Press SPACE to Continue", s_ScreenWidth / 4, s_ScreenHeight / 2 + 70, 25, WHITE);
		DrawText("Press ESC to Exit Game", s_ScreenWidth / 4, s_ScreenHeight / 2 + 30, 25, WHITE);
		DrawText("Press R to Reset", s_ScreenWidth / 4, s_ScreenHeight / 2 - 10, 25, WHITE);

		if (IsKeyPressed(KEY_SPACE) && !entry)
		{
			pausedGame = false;
			mainGamePlay = true;
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			pausedGame = false;
			mainGamePlay = true;
		}

		if (IsKeyPressed(KEY_R) && !entry)
		{
			inMenu = true;
			pausedGame = false;
			mainGamePlay = false;
		}

		entry = false;

		EndDrawing();
	}

}

void EndGame(Score& updateScore)
{
	bool exitEndGame = false;
	while (!exitEndGame)
	{

		BeginDrawing();
		ClearBackground(BLACK);
		if (updateScore.playerLeftScore >= 2)
		{
			DrawText("LEFT PADDLE IS THE WINNER", s_ScreenWidth / 4, s_ScreenHeight / 2, 40, DARKGREEN);
			DrawText("Press R to Reset", s_ScreenWidth / 4, s_ScreenHeight / 2 - 40, 40, WHITE);
		}
		else
		{
			DrawText("RIGHT PADDLE IS THE WINNER", s_ScreenWidth / 4, s_ScreenHeight / 2, 40, DARKGREEN);
			DrawText("Press R to Reset", s_ScreenWidth / 4, s_ScreenHeight / 2 - 40, 40, WHITE);
		}
		if (IsKeyPressed(KEY_R))
		{
			exitEndGame = true;
			inMenu = true;
		}
		EndDrawing();
	}
}