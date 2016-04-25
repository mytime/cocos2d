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

    //绘制正方形
    auto rect = DrawNode::create();
    //arg1:起点维度（左下角0,0），arg2:距离(宽高300，300)，arg3:颜色
    rect->drawRect(Vec2(0,0), Vec2(100,100), Color4F(1.0,0,0,1.0));
    
    
    //创建一个点
    auto dot = DrawNode::create();
    //arg1:维度，arg2:半径2，arg3:颜色 白色
    dot->drawDot(Vec2(0.5,0.5),2,Color4F(1.0,0,0,1.0));

    addChild(rect);
    rect->addChild(dot);
    
    //正方形的位置;屏幕的中心
    rect->setPosition(visibleSize/2);
    //点的位置;相对与正方形
    dot->setPosition(Vec2(3,3));
    
    //设置rect居中
    rect->setContentSize(Size(100,100));
    rect->setAnchorPoint(Vec2(0.5,0.5));
    
    //新建一个计划：执行旋转动画
    schedule([dot,rect](float f){
        rect->setRotation(rect->getRotation()+1);
        //获取当前点在世界坐标中的位置
        auto p = dot->convertToWorldSpace(Vec2(0,0));
        CCLOG("%f,%f",p.x,p.y);
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





