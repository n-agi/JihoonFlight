#include "CTitleScene.h"
#include "IScene.h"
#include "Global.h"
#include "CGameScene.h"

CTitleScene::CTitleScene(){
	StartBG = new IScene();
	StartBG->loadTexture("texture/bg.png");
	StartBG->color=D3DCOLOR_ARGB(0,0,0,0);

	title_icon = new IScene();
	title_icon->loadTexture("texture/2_front.png");
	title_icon->pos=D3DXVECTOR2(100,100);
	title_icon->scale=D3DXVECTOR2(200.f/float(title_icon->texture_width),200.f/float(title_icon->texture_height));

	title_pic = new IScene();
	title_pic->loadTexture("texture/title_pic.png");
	title_pic->pos=D3DXVECTOR2(100.f,0);
	title_pic->scale=D3DXVECTOR2(200.f/float(title_pic->texture_width),200.f/float(title_pic->texture_height));
	
	enter = new IScene();
	enter->loadTexture("texture/enter.png");
	enter->pos=D3DXVECTOR2(-10,500);
	a_c = 0;
	time=0.f;	
}
CTitleScene::~CTitleScene(){
	delete(StartBG);
}

void CTitleScene::update(){
	StartBG->update();
	a_c+=3;
	if(a_c>255) a_c=255; 
	StartBG->color=D3DCOLOR_ARGB(a_c,255,255,255);
	title_icon->color =D3DCOLOR_ARGB(255,a_c,a_c,a_c);
	title_pic->color =D3DCOLOR_ARGB(255,a_c,a_c,a_c);
	enter->color =D3DCOLOR_ARGB(255,a_c,a_c,a_c);
	time+=0.05f;
	title_icon->pos.y=200+50*sin(time);
	//if(title_icon->pos.y < 200) title_icon->pos.y++;

	if(GetKeyState(VK_RETURN) & 0x8000)
	{
		scm->changeScene(new CGameScene());
		return;
	}

}

void CTitleScene::render(){
	StartBG->render();
	title_icon->render();
	title_pic->render();
	enter->render();
}