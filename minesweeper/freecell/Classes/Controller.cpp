#include "Controller.h"
#include "DisplayManager.h"
#include "DataManager.h"
#include "Util.h"

Controller* Controller::ptr_controller = 0;

Controller::Controller(void)
{
}


Controller::~Controller(void)
{
}

Controller* Controller::instance()
{
	if (!ptr_controller) {
		ptr_controller = new Controller();
	}
	return ptr_controller;
}

void Controller::release()
{
	SAFE_DEL_OBJECT(ptr_controller);
}

// init
int Controller::init()
{
	CCLOG("Controller::init.");
	// test mainlayer
	DisplayManager::instance()->mainScene();
	//DisplayManager::instance()->welcomeScene();
	return 1;
}

void Controller::gameOver() {
	CCLOG("Controller:gameOver()");
}
