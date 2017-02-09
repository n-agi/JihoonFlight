#include "IScene.h"

class CTitleScene : virtual public IScene{
public:
	CTitleScene();
	~CTitleScene();

	IScene * StartBG;
	IScene * title_icon;
	IScene * title_pic;
	IScene * enter;
	
	float time;
	short a_c;

	void update();
	void render();
};