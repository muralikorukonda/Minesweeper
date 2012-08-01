#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#define BLOCK_SIZE 40

class BLock : public CCSprite, public CCTargetedTouchDelegate
{


public:
	int index;  // the index of block. index = i * xn + j;
	int number; // n == 0 , nothing, n == -1

    BLock(void);
    virtual ~BLock(void);

    CCRect rect();
    bool initWithTexture(CCTexture2D* aTexture, int type);
    virtual void onEnter();
    virtual void onExit();
    bool containsTouchLocation(CCTouch* touch);
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    virtual CCObject* copyWithZone(CCZone *pZone);

	static BLock* blockWithTexture(CCTexture2D* aTexture);
private:
	bool isTurned;
	void turn();
};

