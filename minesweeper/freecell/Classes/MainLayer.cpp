#include "MainLayer.h"
#include "BLock.h"

#define MENU_AREA_HEIGHT 40
#define INFO_AREA_HEIGHT 40

#define BLOCKS_AREA_X 0
#define BLOCKS_AREA_Y INFO_AREA_HEIGHT
#define BLOCKS_AREA_HEIGHT 400
#define BLOCKS_AREA_WIDTH 320

#define BLOCKS_X_NUMBER 9
#define BLOCKS_Y_NUMBER 9
#define BLOCKS_SIZE 40

MainLayer::MainLayer(void)
{
}


MainLayer::~MainLayer(void)
{
}


// on "init" you need to initialize your instance
bool MainLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(! CCLayer::init());

		// Touch enable
		this->setTouchEnabled(true);

		// Init scene
		this->initScene();
		bRet = true;
	} while (0);

	return bRet;
}

void MainLayer::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCLayer::onEnter();
}

void MainLayer::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}  

// touch event
bool MainLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	CCLOG("MainLayer::ccTouchBegan");
	return true;
}

void MainLayer:: ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {
	CCLOG("MainLayer::ccTouchMoved");
}
void MainLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {
	CCLOG("MainLayer::ccTouchEnded");
}

void MainLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent) {
	CCLOG("MainLayer::ccTouchCancelled");
}

void MainLayer::initScene() {
	// init backgroud
	CCSprite* sprite = CCSprite::spriteWithFile("bg.jpg");
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(ccp(size.width / 2, size.height /2));
	this->addChild(sprite, 0);
	// init menu
	this->initMenuArea();
	// init blocks
	this->initBlocksArea();
	// init info
	this->initInfoArea();
}
void MainLayer::initBlocksArea() {
	// create blocks
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("block.png");
	// create batchnode
	//CCSpriteBatchNode* blockBatchNode = CCSpriteBatchNode::create(texture, 50);
	//this->addChild(blockBatchNode);
	for (int i = 0; i < BLOCKS_X_NUMBER; i++) {
		for (int j = 0; j < BLOCKS_Y_NUMBER; j++) {
			BLock* bl = BLock::blockWithTexture(texture);
	        bl->setPosition(ccp(BLOCKS_AREA_X + BLOCKS_SIZE / 2 + BLOCKS_SIZE * i, BLOCKS_SIZE / 2 + BLOCKS_AREA_Y + BLOCKS_SIZE * j));
			bl->index = i * BLOCKS_X_NUMBER + j;
			this->addChild(bl);
			//blockBatchNode->addChild(bl);
		}
	}
}

void MainLayer::initMenuArea() {

}
void MainLayer::initInfoArea() {

}
