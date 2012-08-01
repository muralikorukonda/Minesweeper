#include "Util.h"

Util* Util::ptr_util = 0;

Util::Util(void)
{
}


Util::~Util(void)
{
}

Util* Util::instance()
{
	if (!ptr_util)
	{
		ptr_util = new Util();
	}
	return ptr_util;
}

void Util::release()
{
	SAFE_DEL_OBJECT(ptr_util);
}