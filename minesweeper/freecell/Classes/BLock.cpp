#include "BLock.h"
#include "Controller.h"
#include "DataManager.h"


Block::Block(void)
{
	this->isTurned = false;
	this->number = -1;
}


Block::~Block(void)
{
}

CCRect Block::rect()
{
    CCSize s = getTexture()->getContentSize();
    return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}

void Block::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite::onEnter();
}

void Block::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}    

bool Block::containsTouchLocation(CCTouch* touch)
{
    return CCRect::CCRectContainsPoint(rect(), convertTouchToNodeSpaceAR(touch));
}

bool Block::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if ( !containsTouchLocation(touch) ) 
		return false;	
    return true;
}

void Block::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
 
}

CCObject* Block::copyWithZone(CCZone *pZone)
{
    this->retain();
    return this;
}

void Block::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCLOG("Touch block %d", index);	   
	if (!this->isTurned) {
		this->isTurned = true;
		this->turn();
	} 
} 

void Block::turn() {
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

Block* Block::blockFactory( int type )
{
	CCTexture2D *texture = CCTextureCache::
		sharedTextureCache()->addImage(IMAGE_BLOCK_TYPE1);
	Block* block = new Block();
	block->initWithTexture(texture , CCRectMake(0, 0, BLOCK_WIDTH, BLOCK_HEIGHT));
	block->autorelease();
	return block;
}
