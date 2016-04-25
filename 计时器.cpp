#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   //static Director* getInstance() 返回一个导演单例   
    Size visibleSize = Director::getInstance()->getVisibleSize(); //返回OpenGL视图的大小，以点为单位
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	////////////////////////////////
	//计时器

	label = LabelTTF::create("yanwanfu","宋体",30);//内容，字体，字号
	addChild(label);//添加到当前层
	
	scheduleUpdate();//调度"update"方法

    return true;
}

//实现update()方法
void  HelloWorld::update(float dt){
	label->setPosition(label->getPosition()+Point(1,1)); //位置自增
	if(label->getPositionX() > 500){
		unscheduleUpdate();//停止执行scheduleUpdate()
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
