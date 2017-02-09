#include "CEnemy.h"
#include "Global.h"
CEnemy::CEnemy(){
	loadTexture("texture/1_front.png");
	hit=false;
	isErase = false;
	hp = 5;
	speed =2.f;
	hit_interval = 0;
	line_wave = 0;
	first = true;
}

CEnemy::~CEnemy(){

}

void CEnemy::update(){
	if(hp <= 0){
		isErase = true; 
		Player->money+=100;
		Player->kill++;
		
	}
	if(this->pos.y>600){
		isErase = true;
	}
	for(auto iter = BulletManager->BulletList.begin() ; iter != BulletManager->BulletList.end() ; iter++){
		if(colCheck(pos.x,pos.y,texture_width,texture_height,(*iter)->pos.x,(*iter)->pos.y,(*iter)->texture_width,(*iter)->texture_height))
		{
			hit=true;
			hp-=Player->damage;
			(*iter)->isErase = true;
			if(hit_interval == 0) hit_interval = 15;
		}
	}
	if(colCheck(pos.x,pos.y,texture_width,texture_height,Player->pos.x,Player->pos.y,Player->texture_width,Player->texture_height)){
		Player->dead = true;
	}
	if(Player->dead){	
		Player->rot += 0.3f;
		Player->pos.y += 3.f;
		Player->pos.x += 1.f;
	}
	if(hit_interval>0){
		hit_interval--;
		hit=true;
	}
	else hit = false;

	this->pos.y += speed;

}

void CEnemy::render(){
	if(hit)
		loadTexture("texture/1_hit.png");
	else loadTexture("texture/1_front.png");
	IScene::render();
}