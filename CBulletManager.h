#pragma once
#include <list>
#include "CBullet.h"
#include "IScene.h"
using namespace std;


class CBulletManager
{
public:
	CBulletManager();
	~CBulletManager();

	list<CBullet*> BulletList;

public:
	void pushBullet( CBullet *p );
	list<CBullet*>::iterator popBullet( CBullet *p );
	void update();
	void render();
};