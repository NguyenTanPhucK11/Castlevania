#include "WBoomerang.h"
#include "Enemy.h"
#include "Brick.h"
#include "Torch.h"
#include "Candle.h"
#include "EffectFactory.h"
#include "Simon.h"

void WBoomerang::Render()
{
	animations[0]->Render(nx, x, y);
}

void WBoomerang::Update(DWORD dt, Scene* scene, vector<LPGAMEOBJECT>* coObjects)
{


	if (this->isDestroy)
	{
		return;
	}
	/*if (nx == DIRECTION::RIGHT)
	{
		this->vx = BOOMERANG_SPEED_VX;
	}
	else if (nx == DIRECTION::LEFT) {
		this->vx = -BOOMERANG_SPEED_VX;
	}*/
	//vx = BOOMERANG_SPEED_VX;
	if (this->x <700) {
		this->isDestroy = true;
	}
	x += dx*2;
	//y += dy;
	vx -= BOOMERANG_GRAVITY*dt;
	CGameObject::Update(dt, scene);

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

}

void WBoomerang::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BOOMERANG_BBOX_WIDTH;
	b = y + BOOMERANG_BBOX_HEIGHT;
}

WBoomerang::WBoomerang() :Weapon()
{
	AddAnimation("BOOMERANG_ANI");
	this->vx = BOOMERANG_SPEED_VX;
	//this->vy = -BOOMERANG_SPEED_VY;
}
