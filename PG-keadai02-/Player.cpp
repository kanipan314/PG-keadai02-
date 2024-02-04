#include "Player.h"
#include <Novice.h>



Player::Player(Vector2 pos, int speed, int radius)
{
	pos_.x = pos.x;
	pos_.y = pos.y;
	speed_ = speed;
	radius_ = radius;
}

void Player::Move(char* keys) {
	if (keys[DIK_D] && keys[DIK_W]) {
		pos_.x += (int)(speed_ * 0.7);
		pos_.y -= (int)(speed_ * 0.7);
	}
	else if (keys[DIK_A] && keys[DIK_S]) {
		pos_.x -= (int)(speed_ * 0.7);
		pos_.y += (int)(speed_ * 0.7);
	}
	else if (keys[DIK_A] && keys[DIK_W]) {
		pos_.x -= (int)(speed_ * 0.7);
		pos_.y -= (int)(speed_ * 0.7);
	}
	else if (keys[DIK_D] && keys[DIK_S]) {
		pos_.x += (int)(speed_ * 0.7);
		pos_.y += (int)(speed_ * 0.7);
	}
	else if (keys[DIK_D]) {
		pos_.x += (int)speed_;

	}
	else if (keys[DIK_A]) {
		pos_.x -= (int)speed_;
	}
	else if (keys[DIK_S]) {
		pos_.y += (int)speed_;
	}
	else if (keys[DIK_W]) {
		pos_.y -= (int)speed_;
	}
}


void Player::SetPosition(Vector2 pos) {

	pos_.x = pos.x;
	pos_.y = pos.y;


}

void Player::SetSpeed(int speed) {

	speed_ = speed;

}

void Player::Drow(int posX, int posY, int name, float scale) {
	Novice::DrawSprite(posX, posY, name, scale, scale, 0.0, WHITE);
}

