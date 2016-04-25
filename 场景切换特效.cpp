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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//场景特效
	/*
	Sprite 是一个2D图像节点
	
	创建成功之后，Sprite 的大小与图片大小一致。偏移量为 (0,0)。
	参数：filename	图像文件的路径，例如："scene1/monster.png"
	返回：一个 Sprite 实例（已经被 autorelese）
	*/
	auto background = Sprite::create("a.jpg");//使用一个图片文件创建 Sprite(精灵)。
	background->setPosition(visibleSize / 2);//居中
	addChild(background);//添加到当前场景

	scheduleOnce([visibleSize](float f){
		//创建新的场景
		auto newScene=Scene::create();//创建一个新场景对象。返回1个 autorelease 的场景对象。
		auto newBackground=Sprite::create("b.jpg");//使用一个图片文件创建 Sprite(精灵)，背景
		newBackground->setPosition(visibleSize/2);//居中
		newScene->addChild(newBackground);//背景添加到场景中

		//static TransitionCrossFade* create创建一个交叉淡入淡出过渡效果。
		//参数：1 持续时间,以秒为单位，	2 一个给定的场景
		//auto transition = TransitionCrossFade::create(1,newScene);
		//
		//翻页效果
		auto transition = TransitionPageTurn::create(1, newScene,false);

		//Director 导演类，负责创建和处理主窗口，以及管理场景执行
		//getInstance 返回一个导演的单例
		//replaceScene 用新的场景替换运行场景。终止正在运行的场景。 只能在有运行场景时调用它
		Director::getInstance()->replaceScene(transition);


	},2,"Test");

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
