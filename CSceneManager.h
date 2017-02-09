#pragma once

#include "IScene.h"

class CSceneManager{
public:
	CSceneManager();
	~CSceneManager();
	IScene *Scene;

	void update();
	void render();
	void changeScene( IScene *p, bool isErase=true );
};