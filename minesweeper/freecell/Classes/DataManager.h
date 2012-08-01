#pragma once

#include "Util.h"

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

