#pragma once
#include "cocos2d.h"
#include "Util.h"

using namespace cocos2d;

class DisplayManager
{
public:
	static DisplayManager* instance();
	static void release();
	~DisplayManager(void);

	// show welcome scene
	void welcomeScene();

	// show main scene
	void mainScene();

	// show option scene
	void optionScene();
protected:
	DisplayManager(void);

	// go to scene
	void gotoScene(CCLayer* layer);

private:
	static DisplayManager* ptr_displayer;
	
};

