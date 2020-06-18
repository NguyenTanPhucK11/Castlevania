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
	if (!setVelocyet)
	{
		if (nx==DIRECTION::LEFT)
		{
			vx = -BOOMERANG_SPEED_VX;
		}
		else
		{
			vx = BOOMERANG_SPEED_VX;
		}
		setVelocyet = true;
	}
	if (nx== DIRECTION::LEFT)
	{
		vx += 0.0012*dt;
	}
	else
	{
		vx += -0.0009 * dt;
	}

	D3DXVECTOR2 cam;
	if (dynamic_cast<PlayScene*>(scene))
	{
		auto pScene = dynamic_cast<PlayScene*>(scene);
		cam=pScene->GetCamera();
		if (this->x > cam.x + SCREENSIZE::WIDTH || this->x < cam.x 
			|| isReturn) {
			this->isDestroy = true;
			isReturn = false;
		}
		
		if ((this->x > pScene->GetSimon()->x + 64 && nx == DIRECTION::RIGHT)
			|| (this->x < pScene->GetSimon()->x - 128 && nx == DIRECTION::LEFT)) {
			isFly = true;
		}
		if (((this->x <= pScene->GetSimon()->x + 32 && nx == DIRECTION::RIGHT)
			|| (this->x >= pScene->GetSimon()->x && nx == DIRECTION::LEFT)) 
			&& this->y - pScene->GetSimon()->y > 0 && isFly) {
			isReturn = true;
			//DebugOut(L"y %f\n", this->y);
			//DebugOut(L"simon y %f\n", pScene->GetSimon()->y);
			isFly = false;
		}
	}
	
	x += dx;
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
