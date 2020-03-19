﻿#include "Whip.h"
#include"Torch.h"
void Whip::Render()
{
	int ani;
	switch (state)
	{			
	case NORMAL:
		ani = WHIP_ANI_NORMAL;
		break;
	case CHAIN:
		ani = WHIP_ANI_CHAIN;
		break;
	case MORINGSTAR:
		ani = WHIP_ANI_MORNINGSTAR;
		break;
	}
	animations[ani]->Render(nx, x, y);
	RenderBoundingBox();// vẽ bbox
}

void Whip::GetBoundingBox(float& l, float& t, float& r, float& b)
{

	if (nx < 0)
	{
		l = x + 20;
		t = y;
		r = l+WHIP_BBOX_NORMAL_WIDTH;
		b = y + WHIP_BBOX_NORMAL_HEIGHT;
	}
	else
	{
		l = x + 140;
		t = y;
		r = l + WHIP_BBOX_NORMAL_WIDTH;
		b = y + WHIP_BBOX_NORMAL_HEIGHT;


	}

}

void Whip::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	if (animations[WHIP_ANI_NORMAL]->GetCurrentFrame()<2)
	{
		return;
	}
	//xử lý va chạmgiữaa whip và các object dùng aabb

	for (size_t i = 0; i < colliable_objects->size(); i++)
	{
		if (dynamic_cast<CTorch*>(colliable_objects->at(i))) // kiểm tra phải torch không
		{
			CTorch * torch= dynamic_cast<CTorch*>(colliable_objects->at(i));
			if (this->isColliding(torch))// kiểm tra có va chạm k
			{
				torch->SetDestroy(); // có va chạm hủy torch
			}
		}
	}



}

void Whip::SetState(WHIPSTATE state)
{
	switch (state)
	{	
	case NORMAL:
		break;
	case CHAIN:
		break;
	case MORINGSTAR:
		break;
	default:
		break;
	}
	this->state = state;
}
