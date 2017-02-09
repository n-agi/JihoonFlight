#pragma once
#include "IScene.h"

class CTestObject : virtual public IScene
{
public:
	CTestObject();
	~CTestObject();

	void update();
	void render();
};