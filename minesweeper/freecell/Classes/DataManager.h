#pragma once

#include "Util.h"

#define IMAGE_BLOCK_TYPE1 "xblock_x2.png"
#define IMAGE_BLOCK_TYPE2 "xblock2.png"

#define BLOCK_WIDTH 40
#define BLOCK_HEIGHT 40

class DataManager
{
public:
	static DataManager* instance();
	static void release();

	~DataManager(void);
protected:
	DataManager(void);
private:
	static DataManager* ptr_datamanager;	
};

