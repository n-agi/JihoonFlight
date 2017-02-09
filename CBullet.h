#pragma once
//#include "CBulletManager.h"
#include "IScene.h"

class CBullet : public virtual IScene{
public:
	CBullet();
	~CBullet();
	int speed;
	bool isErase;

	void update();
	void render();

};