#include <Windows.h>
#include <map>
#include <d3d9.h>
#include <d3dx9.h>
#include "CSceneManager.h"
#include "CBulletManager.h"
#include "CPlayer.h"

using namespace std;

extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern LPD3DXSPRITE g_pSprite;
extern CSceneManager *scm;
extern map<char*,LPDIRECT3DTEXTURE9> TextureMap;
LPDIRECT3DTEXTURE9 getTexture(char *path);
void clearTexture();
extern CBulletManager *BulletManager;
extern CPlayer *Player;

bool colCheck ( int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2 );