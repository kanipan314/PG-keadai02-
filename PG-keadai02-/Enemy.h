#pragma once

#include <Struct.h>

class Enemy
{

public:



	Enemy(Vector2 pos, Vector2 speed, int radius);


	void Update();

	void Draw(int eneposX, int eneposY, int name, float scale);

	void SetPosition(Vector2 pos);
	void SetSpeed(Vector2 speed);

	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };

private:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;

};

