#include "IScene.h"
#include "Global.h"

IScene::IScene()
{
	pos=scalingCenter=rotationCenter=D3DXVECTOR2(0,0);
	scale=D3DXVECTOR2(1,1);
	rot=0.f;
	D3DXMatrixIdentity ( &mat );

	texture=NULL;

	color=D3DCOLOR_ARGB(255,255,255,255);

	texture_width=0;
	texture_height=0;
}

IScene::~IScene()
{
	texture=NULL;
	//지우는건 clearTexure 에서
}

void IScene::loadTexture(char *path)
{
	texture=getTexture(path);

	D3DSURFACE_DESC desc;
	texture->GetLevelDesc(0,&desc);

	texture_width=desc.Width;
	texture_height=desc.Height;
}

void IScene::update()
{
	//virtual
}

void IScene::render()
{
	D3DXMatrixTransformation2D( &mat, &scalingCenter, 0.f, &scale, &rotationCenter, rot, &pos );

	if( texture )
	{
		g_pSprite->SetTransform( &mat );

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		g_pSprite->Draw( texture, NULL, NULL, NULL,color); 

		g_pSprite->End();
	}

}