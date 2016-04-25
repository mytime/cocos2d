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
	//plist文件读写

	FileUtils *fu = FileUtils::getInstance();
	ValueMap vm = fu->getValueMapFromFile("data.plist");
	log("%s",vm["name"].asString().c_str());
	

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
