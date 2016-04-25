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

	auto icon = Sprite::create("CloseSelected.png");//使用一个图片文件创建 Sprite
	addChild(icon);
	icon->setPosition(visibleSize/2);

	auto size = icon->getContentSize();
	CCLOG("icon width:%f,icon height:%f",size.width,size.height);

	//时间机器，持续输出
	schedule([icon](float f){
		auto size = icon->getContentSize();
		CCLOG("icon width:%f,icon height:%f", size.width, size.height);
	},"test");

	/////////////////////////////////////
	//Vector用法
/*	Vector<Label*> vec; //Label类型的队列
	auto l1 = Label::create();
	auto l2 = Label::create();

	l1->setString("L 1");
	l2->setString("L 2");
	l1->setSystemFontSize(50);
	l2->setSystemFontSize(50);

	vec.pushBack(l1); //向队列插入Label类型的值
	vec.pushBack(l2);

	int i=0;
	for (auto ll:vec)
	{
		i++;
		ll->setPosition(Vec2(visibleSize.width/2,i*100));
		addChild(ll);
	}
*/

	////////////////////////////////////
	//Map用法
	Map<std::string,Label*> map;

	auto l1 = Label::create();
	auto l2 = Label::create();

	l1->setString("L 1");
	l2->setString("L 2");
	l1->setSystemFontSize(50);
	l2->setSystemFontSize(50);

	l1->setPosition(Vec2(visibleSize.width/2,50));//Vec2(x,y)
	l2->setPosition(Vec2(visibleSize.width/2,100));

	map.insert("l1",l1);
	map.insert("l2",l2);
	
	addChild(map.at("l2"));

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
