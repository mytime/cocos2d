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
	//log 用法
	log("Hello Cocos2dx %d",1000);

	///////////////////////////////
	//MessageBox 用法

/*	MessageBox("消息内容","消息标题"); */

	////////////////////////////////
	//LabelTTF 用法

/*	LabelTTF *label = LabelTTF::create();
	label->setString("How are you");
	label->setFontSize(50);
	label->setPosition(visibleSize.width/2,visibleSize.height/2);
	addChild(label); */

	////////////////////////////////
	//TextFieldTF 用法
	TextFieldTTF *tf = TextFieldTTF::textFieldWithPlaceHolder("在这里输入","宋体",20);
	tf->setPosition(visibleSize.width/2,visibleSize.height/2);

	addChild(tf);

	//创建单点触摸事件监听器。
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [tf](Touch *t,Event *event){ //匿名函数
		
		if (tf->getBoundingBox().containsPoint(t->getLocation())){
				tf->attachWithIME();//打开键盘和接收输入文本

		}
		else
		{
			tf->detachWithIME();//文本输入结束并关闭键盘
		}

		return false;
		
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener,tf);//给一个指定的事件添加一个事件监听器，该监听器带有基于场景图的优先级




    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
