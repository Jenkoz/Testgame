#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 48

class CBrick : public CGameObject {
public: 
	CBrick(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
};

class CMario : public CGameObject
{
protected:
	float vx;
	int state;
public:
	CMario(float x, float y, float vx);
	void Render();
	void Update(DWORD dt);
	int GetState() { return state; }
	void SetState(int state) { this->state = state; }
};

class CGoomba : public CGameObject
{
protected:
	float vx;
	int state;
public:
	CGoomba(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
	int GetState() { return state; }
	void SetState(int state) { this->state = state; }
	//12312312312
};



