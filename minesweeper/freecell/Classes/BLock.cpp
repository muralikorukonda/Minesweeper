#include "BLock.h"
#include "Controller.h"


BLock::BLock(void)
{
	this->isTurned = false;
	this->number = -1;
}


BLock::~BLock(void)
{
}

CCRect BLock::rect()
{
    CCSize s = getTexture()->getContentSize();
    return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}


bool BLock::initWithTexture(CCTexture2D* aTexture, int type)
{
    if( CCSprite::initWithTexture(aTexture) ) 
    {
       
    }
    
    return true;
}

void BLock::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite::onEnter();
}

void BLock::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}    

bool BLock::containsTouchLocation(CCTouch* touch)
{
    return CCRect::CCRectContainsPoint(rect(), convertTouchToNodeSpaceAR(touch));
}

bool BLock::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if ( !containsTouchLocation(touch) ) 
		return false;	
    return true;
}

void BLock::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
 
}

CCObject* BLock::copyWithZone(CCZone *pZone)
{
    this->retain();
    return this;
}

void BLock::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCLOG("Touch block %d", index);	   
	if (!this->isTurned) {
		this->isTurned = true;
		this->turn();
	} 
} 

BLock* BLock::blockWithTexture(CCTexture2D* aTexture)
{
    BLock* block = new BLock();
    block->initWithTexture( aTexture , 0);
    block->autorelease();
    return block;
}

void BLock::turn() {
	if ( this->number == -1) {
		// change image
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("ll.png");
	    this->setTexture(texture);
		// game over
		Controller::instance()->gameOver();
	} else if ( this->number == 0) {
		// TODO:: delete self nothing
		this->setOpacity(0);
	} else {
		// show number
	}
}