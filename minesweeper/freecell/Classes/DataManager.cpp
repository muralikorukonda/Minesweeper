#include "DataManager.h"

DataManager* DataManager::ptr_datamanager = 0;
DataManager::DataManager(void)
{
}


DataManager::~DataManager(void)
{
}

DataManager* DataManager::instance()
{
	if (!ptr_datamanager)
	{
		ptr_datamanager = new DataManager();
	}
	return ptr_datamanager;
}

void DataManager::release()
{
	SAFE_DEL_OBJECT(ptr_datamanager)
}
