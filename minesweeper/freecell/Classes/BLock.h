#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#define BLOCK_SIZE 40

class Block : public CCSprite, public CCTargetedTouchDelegate
{


public:
	int index;  // the index of block. index = i * xn + j;
	int number; // n == 0 , nothing, n == -1

	static Block* blockFactory(int type);

    Block(void);
    virtual ~Block(void);

    CCRect rect();
    virtual void onEnter();
    virtual void onExit();
    bool containsTouchLocation(CCTouch* touch);
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    virtual CCObject* copyWithZone(CCZone *pZone);
private:
	bool isTurned;
	void turn();
};

