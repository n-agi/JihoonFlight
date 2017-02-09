#include "CBulletManager.h"	
CBulletManager::CBulletManager()
{

}

CBulletManager::~CBulletManager()
{
	for(auto iter=BulletList.begin(); iter!=BulletList.end(); iter++)
		delete(*iter);
	BulletList.clear();
}

list<CBullet*>::iterator CBulletManager::popBullet( CBullet *p )
{
	for(auto iter=BulletList.begin(); iter!=BulletList.end(); iter++)
	{
		if((*iter)==p)
		{
			delete(*iter);
			iter=BulletList.erase(iter);
			return iter;
		}
	}
}

void CBulletManager::pushBullet( CBullet *p )
{
	BulletList.push_back(p);
}

void CBulletManager::update()
{
	for(auto iter=BulletList.begin(); iter!=BulletList.end(); iter++)
	{
		//auto 의 자료형은 list<CBullet>::iterator
		(*iter)->update();

		if((*iter)->isErase)
		{
			delete(*iter);
			iter=BulletList.erase(iter);
			if(iter==BulletList.end()) break;
		}
	}

}

void CBulletManager::render()
{
	for(auto iter=BulletList.begin(); iter!=BulletList.end(); iter++)
		(*iter)->render();
}