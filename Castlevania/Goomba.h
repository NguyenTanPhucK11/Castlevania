#pragma once
#include "GameObject.h"

#define GOOMBA_WALKING_SPEED 0.05f;

#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 15
#define GOOMBA_BBOX_HEIGHT_DIE 9

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_DIE 200

#define GOOMBA_ANI_WALKING 0
#define GOOMBA_ANI_DIE 1


 enum class GOOMBASTATE
{
	WALKING,
	DIE
};


class CGoomba : public CGameObject
{
	GOOMBASTATE state;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, Scene* scene, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();


public: 	
	CGoomba() {
		state = GOOMBASTATE::WALKING;
	}
	GOOMBASTATE GetState() {
		return this->state;
	}

	void SetState(GOOMBASTATE state);
};