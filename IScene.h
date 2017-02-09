#pragma once
#include <d3dx9.h>

class IScene
{
public:
	IScene();
	virtual ~IScene();

public:
	virtual void update();
	virtual void render();

	void loadTexture( char *path );
	
	LPDIRECT3DTEXTURE9 texture;

	D3DXVECTOR2 pos,scale,scalingCenter,rotationCenter;
	float rot;

	int texture_width;
	int texture_height;
	
	D3DXMATRIX mat;

	DWORD color;

};