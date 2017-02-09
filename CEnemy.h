#pragma once
#include "IScene.h"

class CEnemy : virtual public IScene{
public:
	CEnemy();
	~CEnemy();
	bool isErase;
	int hp;
	float speed;
	bool first;
	int line_wave;
	int revive_interval;
	bool hit;
	int hit_interval;
	void update();
	void render();
};