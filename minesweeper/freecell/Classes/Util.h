#pragma once
#include "BLock.h"

#define SAFE(command) do \
{\
	command; \
} while (0);

#define SAFE_DEL_OBJECT(ptr)  SAFE(if ((ptr)) { delete ptr; ptr = 0;})
#define SAFE_DEL_ARRAY(ptr)  SAFE(if ((ptr)) { delete []ptr; ptr = 0;})

class Util
{
public:
	static Util* instance();
	static void release();
	virtual ~Util(void);

	
protected:
	Util(void);
	
private:
	static Util* ptr_util;
};

