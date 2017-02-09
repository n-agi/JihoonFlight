#include "CPlayer.h"
#include "Global.h"

CPlayer::CPlayer(){
	loadTexture("texture/2_front.png");
	pos=D3DXVECTOR2(150.f,450.f);
	attack_Interval=0;
	money = 0;
	damage = 1;
	tier = 0;
	score=0;
	kill=0;
	tmp = 0;
	dead = false;
	levelup=false;
	level = new IScene();
	level->loadTexture("texture/level.png");
	level->pos=D3DXVECTOR2(-10,500);
}

CPlayer::~CPlayer(){

}

void CPlayer::update(){
	
	attack_Interval++;

	if(GetKeyState(VK_RETURN) & 0x8000 && attack_Interval >= 10 && !dead)
	{
		attack_Interval=0;
		CBullet *Bullet=new CBullet();
		Bullet->pos=D3DXVECTOR2(this->pos.x+20,this->pos.y);
		BulletManager->pushBullet(Bullet);
	}

	if((GetKeyState(VK_LEFT) &0x8000) && !dead){
		if(this->pos.x > 0) this->pos.x-=4;
	}
	
	if((GetKeyState(VK_RIGHT) & 0x8000) && !dead){
		if(this->pos.x < 380-texture_width) this->pos.x+=4;
	}
	if(money > (500+tier*100)){
		money = 0;
		damage++;
		tier++;
		levelup = true;
		level->color = D3DCOLOR_ARGB(0,0,0,0);
		level->pos = D3DXVECTOR2(-10,500);
		tmp = 0;
	}
	if(pos.y > 600.f){
		pos.y = 200.f;
		rot=0.f;
		WCHAR buf[128];
		wsprintf(buf,L"SCORE : %d",kill*100);
		MessageBox(NULL,buf,L"GAME OVER",NULL);
		PostQuitMessage(0);
	}
	if(levelup){
		tmp+=4;
		if(tmp>255) tmp = 255;
		level->pos.y-=4;
		if(level->pos.y < -100 ) levelup=false;
		level->color = D3DCOLOR_ARGB(tmp,255,255,255);
	}
}

void CPlayer::render(){
	IScene::render();
	if(levelup){
		level->render();
	}
}