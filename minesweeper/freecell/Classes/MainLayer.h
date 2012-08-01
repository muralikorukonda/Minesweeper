#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class MainLayer : public CCLayer
{
public:
	MainLayer(void);
	virtual ~MainLayer(void);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	void onEnter();
    void onExit();

	// touch event
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	// implement the "static node()" method manually
	LAYER_CREATE_FUNC(MainLayer);
private:
	void initScene();
	void initBlocksArea();
	void initMenuArea();
	void initInfoArea();
};

