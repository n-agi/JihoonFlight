#include "CSceneManager.h"
#include "CTitleScene.h"
CSceneManager::CSceneManager()
{
	Scene=NULL;
}

CSceneManager::~CSceneManager()
{
	delete(Scene);
}

void CSceneManager::update()
{
	if(Scene)
		Scene->update();
}

void CSceneManager::render()
{
	if(Scene)
		Scene->render();
}

void CSceneManager::changeScene( IScene *p, bool isErase )
{
	if( Scene != NULL )
	{
		if( isErase ) delete(Scene);
	}

	Scene=p;
}