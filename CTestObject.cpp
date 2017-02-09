#include "CTestObject.h"

CTestObject::CTestObject()
{
	loadTexture("texture/jihoon.jpg");
}

CTestObject::~CTestObject()
{

}

void CTestObject::update()
{
	IScene::update();

	rotationCenter=D3DXVECTOR2(texture_width/2, texture_height/2);
	scalingCenter=D3DXVECTOR2(texture_width/2, texture_height/2);
	
	rot+=0.1;
	scale=D3DXVECTOR2(10,10);
	
	if(GetKeyState(VK_UP) & 0x8000)
	{
		pos.y-=10;
	}
	if(GetKeyState(VK_DOWN) & 0x8000)
	{
		pos.y+=10;
	}
	if(GetKeyState(VK_LEFT) & 0x8000)
	{
		pos.x-=10;
	}
	if(GetKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x+=10;
	}
}

void CTestObject::render()
{
	IScene::render();
}