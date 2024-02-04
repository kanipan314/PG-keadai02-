#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Vector2 speed, int radius)
{
	posX_ = pos.x;
	posY_ = pos.y;
	speedX_ = speed.x;
	speedY_ = speed.y;
	radius_ = radius;

}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Draw(int eneposX, int eneposY, int name, float scale)
{
	Novice::DrawSprite(eneposX, eneposY, name, scale, scale, 0.0f, WHITE);

}

void Enemy::SetPosition(Vector2 pos) {

	posX_ = pos.x;
	posY_ = pos.y;


}

void Enemy::SetSpeed(Vector2 speed) {

	speedX_ = speed.x;
	speedY_ = speed.y;


}