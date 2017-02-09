#include "CGameScene.h"
#include "IScene.h"
#include "Global.h"

CGameScene::CGameScene(){
	StartBG = new IScene();
	StartBG->loadTexture("texture/bg.png");

	StartBG2 = new IScene();
	StartBG2->loadTexture("texture/bg.png");
	StartBG2->pos.y = -600;
	
	BulletManager = new CBulletManager();
	Player = new CPlayer();

	for(int i=0; i<5; i++)
	{
		Enemy[i]= new CEnemy();
		Enemy[i]->pos=D3DXVECTOR2(15+(i*75),-100);
	}
	regen = false;
	line_wave = 0;

}
CGameScene::~CGameScene(){
	delete(StartBG);
	delete(BulletManager);
	delete(Player);

	for(int i=0; i<5; i++)
	{
		if(Enemy[i]) delete(Enemy[i]);
	}
}

void CGameScene::update(){
	StartBG->update();
	StartBG2->update();
	Player->update();
	BulletManager->update();
	StartBG->pos.y++;
	StartBG2->pos.y++;
	for(int i=0; i<5; i++)
	{
		if(Enemy[i] != NULL)
		{
			Enemy[i]->update();
			if(Enemy[i]->isErase)
			{
				delete(Enemy[i]);
				Enemy[i]=NULL;
			}
		}
	}
	regen = true;
	for(int i = 0 ; i < 5 ; i++){
		if(Enemy[i] != NULL)
		{
			regen = false;
		}
	}
	if(regen){
		line_wave++;
		for(int i = 0 ; i < 5 ; i++){
			if(Enemy[i] == NULL){
				Enemy[i] = new CEnemy();
				Enemy[i]->pos = D3DXVECTOR2(15+(i*75),-100);
				Enemy[i]->speed += 1.f;
				Enemy[i]->hp = 5+(line_wave*1.3);			
			}
		}
	}
	if(StartBG->pos.y >= 600)
		StartBG->pos.y = -600;
	if(StartBG2->pos.y >= 600)
		StartBG2->pos.y = -600;
}

void CGameScene::render(){
	StartBG->render();
	StartBG2->render();
	BulletManager->render();
	Player->render();

	for(int i=0; i<5; i++)
	{
		if(Enemy[i]) Enemy[i]->render();
	}
	
}