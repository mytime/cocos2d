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

	//////////////////////////////
	//Value用法

	Value v1 = Value("abc");
	Value v2 = Value(123);
	Value v3 = Value(true);

	CCLOG("%s %d %s",v1.asString().c_str(),v2.asInt(),v3.asBool() ==true?"True":"False");
	CCLOG("%s %s %s",v1.asString().c_str(),v2.asString().c_str(),v3.asString().c_str());

	Value v4=Value::Null;
	v4=v1;
	v4=v2;
	v4=v3;

	CCLOG("%s %s",v4.getType()==Value::Type::BOOLEAN?"True":"False",v4.asString().c_str());

	/////////////////////////////
	//ValueVector 用法
	ValueVector vector;
	vector.push_back(Value("hello"));
	vector.push_back(v1);
	vector.push_back(v2);
	for(auto v:vector){
		CCLOG("Vector %s",v.asString().c_str());
	}

	/////////////////////////////
	//ValueMap 用法
	ValueMap map;
	map["a"]=v2;
	map["b"]=v1;
	map["c"]=Value("how are you ");

	for(auto m:map){
		CCLOG("%s=%s",m.first.c_str(),m.second.asString().c_str());
	}



    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
