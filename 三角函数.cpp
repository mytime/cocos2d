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
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //获取屏幕的大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //记录当前的角度
    _angle=0;
    
    //绘制一个点
    auto dot = DrawNode::create();
    //arg1:维度，arg2:半径，arg3:颜色
    dot->drawDot(Vec2(0,0),3,Color4F(1.0,1.0,1.0,1.0));
    addChild(dot);
    
    //居中
    dot->setPosition(visibleSize/2);
    
    //新建一个计划：执行旋转动画
    schedule([dot,this,visibleSize](float f){
        //sin三角函数正弦取值范围-1~1
        //sin(角度)
//        dot->setPositionY(visibleSize.height/2+sin(_angle)*100.0);
        dot->setPositionY(visibleSize.height/2+sin(_angle)*100.0);

//        dot->setPositionX(visibleSize.width/2+sin(_angle)*100.0);
         dot->setPositionX(visibleSize.width/2+cos(_angle)*50.0);
        //每帧加0.1
        _angle+=0.1;
        
        
    },"Test");
    
    

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}





