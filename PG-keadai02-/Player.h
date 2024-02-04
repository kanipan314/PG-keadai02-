#pragma once

#include <Struct.h>


class Player
{
public:


	Player(Vector2 pos, int speed, int radius);

	void Move(char* key);
	void Drow(int posX, int posY, int name, float scale);

	void SetPosition(Vector2 pos);

	void SetSpeed(int speed);


	int GetPosX() { return pos_.x; };
	int GetPosY() { return pos_.y; };
	int GetRadius() { return radius_; };
	int GetSpeed() { return speed_; };


private:
	Vector2 pos_;
	int speed_;
	int radius_;
};


