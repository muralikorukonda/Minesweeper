#pragma once
#include "Util.h"


class Controller
{
public:
	static Controller* instance();
	static void release();
	~Controller(void);

	// init
	int init();
	void gameOver();

protected:
	Controller(void);

private:
	static Controller* ptr_controller;	
	
};

