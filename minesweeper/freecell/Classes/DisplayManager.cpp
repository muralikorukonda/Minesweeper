#include "DisplayManager.h"

#include "WelcomeLayer.h"
#include "OptionLayer.h"
#include "AboutLayer.h"
#include "MainLayer.h"

DisplayManager* DisplayManager::ptr_displayer = 0;

DisplayManager::DisplayManager(void)
{
}


DisplayManager::~DisplayManager(void)
{
}

DisplayManager* DisplayManager::instance()
{
	if (!ptr_displayer)
	{
		ptr_displayer = new DisplayManager();
	}
	return ptr_displayer;

}

void DisplayManager::release()
{
	SAFE_DEL_OBJECT(ptr_displayer);
}

void DisplayManager::welcomeScene() {
	CCLOG("DisplayManager:: show welcome scene.");
	gotoScene(WelcomeLayer::create());
}

// show main scene
void DisplayManager::mainScene() {
	CCLOG("DisplayManager:: show main scene.");
	gotoScene(MainLayer::create());
}

// show option scene
void DisplayManager::optionScene() {
	CCLOG("DisplayManager:: show option scene.");
	gotoScene(OptionLayer::create());
}

void DisplayManager::gotoScene(CCLayer* layer) {
	// check layer
	if (!layer) {
		CCLOG("DisplayManager::gotoScene layer is null.");
		return;
	}
	// create scene
	CCScene * scene = NULL;
	scene = CCScene::create();
	if (!scene) {
		CCLOG("DisplayManager::gotoScene senen create failed.");
		return;
	}
	
	// add layer as a child to scene
	scene->addChild(layer);

	// run scene
	CCDirector* director = CCDirector::sharedDirector();
	if (!director->getRunningScene()) {
		director->runWithScene(scene);
	} else {
		director->replaceScene(scene);
	}	
}