#include "CBullet.h"

CBullet::CBullet(){
	isErase = false;
	speed=30.f;
	loadTexture("texture/hammer.png");
	//scale = D3DXVECTOR2(0.1f,0.1f);
	rotationCenter = scalingCenter = D3DXVECTOR2(texture_width/2, texture_height/2);
}

CBullet::~CBullet(){

}

void CBullet::update(){
	pos.y-=speed;
	if(pos.y < -texture_height) isErase = true;
	rot+=0.3f;
}

void CBullet::render(){
	IScene::render();
}