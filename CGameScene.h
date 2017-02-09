#include "IScene.h"
#include "CEnemy.h"
class CGameScene : virtual public IScene{
public:
	CGameScene();
	~CGameScene();

	IScene * StartBG;
	IScene * StartBG2;
	CEnemy *Enemy[5];
	float time;
	short a_c;
	bool regen;
	int line_wave;

	void update();
	void render();
};