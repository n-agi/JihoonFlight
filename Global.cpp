#include "Global.h"

LPDIRECT3D9 g_pD3D;
LPDIRECT3DDEVICE9 g_pd3dDevice;
LPD3DXSPRITE g_pSprite;
CBulletManager *BulletManager;
CSceneManager *scm;
map<char*,LPDIRECT3DTEXTURE9> TextureMap;
CPlayer *Player;

bool colCheck ( int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2 )
{
	RECT r1,r2;
	RECT tmpRet;

	r1.left=x1;
	r1.right=x1+w1;
	r1.top=y1;
	r1.bottom=y1+h1;

	r2.left=x2;
	r2.right=x2+w2;
	r2.top=y2;
	r2.bottom=y2+h2;

	return bool(IntersectRect(&tmpRet,&r1,&r2));

}

LPDIRECT3DTEXTURE9 getTexture(char *path)
{
	if(TextureMap[path] != NULL) return TextureMap[path]; // return texture that has same path

	D3DXCreateTextureFromFileExA(
		g_pd3dDevice,
		path,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		NULL,
		NULL,
		NULL,
		&TextureMap[path]
	);

	return TextureMap[path];

}

void clearTexture()
{
	for(auto  iter=TextureMap.begin(); iter!=TextureMap.end(); iter++)
	{
		iter->second->Release(); // texture unload
	}
	TextureMap.clear();
}