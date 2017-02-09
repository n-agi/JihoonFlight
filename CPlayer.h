#pragma once
#include "IScene.h"

class CPlayer : virtual public IScene{
public:
	CPlayer();
	~CPlayer();

	int attack_Interval;
	int money;
	void update();
	void render();
	int damage;
	int tier;
	int kill;
	int score;
	bool dead;
	bool levelup;
	int tmp;
	IScene *level;
};