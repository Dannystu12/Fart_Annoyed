/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f + 24.0f, 300.0f), Vec2(-1.0f, -1.0f)),
	walls(Rectf::FromCenter(Graphics::GetScreenRect().GetCenter(), fieldWidth / 2.0f, fieldHeight / 2.0f), 
		wallThickness, wallColor),
	soundPad(L"Sounds\\arkpad.wav"),
	brickSound(L"Sounds\\arkbrick.wav"),
	fartSound(L"Sounds\\fart.wav"),
	paddle(Vec2(400.0f, 500.0f), 50.0f, 15.0f)
{

	

	const Vec2 topLeft(walls.GetInnerBounds().left, topSpace);

	for (int y = 0; y < nBricksDown; y++)
	{
		const Color c = brickColors[y];
		for (int x = 0; x < nBricksAcross; x++)
		{
			const int currentIndex = y * nBricksAcross + x;
			const Vec2 brickTopLeft = topLeft + Vec2(x * brickWidth, y*brickHeight);
			bricks[currentIndex] = Brick(
				Rectf(brickTopLeft, brickWidth, brickHeight), 
				c);
		}
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
		
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(const float dt)
{

	if (gameOver) return;

	ball.Update(dt);
	paddle.Update(wnd.kbd, dt);
	paddle.DoWallCollision(walls.GetInnerBounds());

	bool collisionHasHappened = false;
	float curColDistSq;
	int colIndex;

	for (int i = 0; i < nBricks; i++)
	{
		const Brick& brick = bricks[i];
		if (!brick.CheckBallCollision(ball)) continue;
		const float newColDistSq = (ball.GetPosition() - brick.GetCenter()).GetLengthSq();

		if (collisionHasHappened && newColDistSq < curColDistSq)
		{
			colIndex = i;
			curColDistSq = newColDistSq;
		}
		else
		{
			colIndex = i;
			curColDistSq = newColDistSq;
			collisionHasHappened = true;
		}
	}
	
	if (collisionHasHappened)
	{
		paddle.ResetCooldown();
		bricks[colIndex].ExecuteBallCollision(ball);
		brickSound.Play();
	}

	if (paddle.DoBallCollision(ball)) soundPad.Play();

	const int wallCollideResult = ball.DoWallCollision(walls.GetInnerBounds());

	if (wallCollideResult == 1) {
		paddle.ResetCooldown();
		soundPad.Play();
	}
	else if (wallCollideResult == 2)
	{
		gameOver = true;
		fartSound.Play();
	}
}

void Game::ComposeFrame()
{
	walls.Draw(gfx);
	ball.Draw(gfx);
	for (const Brick& brick : bricks)
	{
		brick.Draw(gfx);
	}
	paddle.Draw(gfx);

	if (gameOver)
	{
		SpriteCodex::DrawGameOver(walls.GetInnerBounds().GetCenter(), gfx);
	}
}
