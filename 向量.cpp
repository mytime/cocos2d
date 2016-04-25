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

    
    
    //向量(包含了大小和方向)
    //arg1:x ,arg2:y
    _direction.set(random(-1.0f, 1.0f), random(-1.0f,1.0f));
    //标准化方向上的大小是1
    _direction.normalize();
    
    //绘制一个点
    auto dot = DrawNode::create();
    //arg1:维度，arg2:半径，arg3:颜色
    dot->drawDot(Vec2(0,0),3,Color4F(1.0,1.0,1.0,1.0));
    addChild(dot);
    
    //持续执行计划：
    schedule([dot,this,visibleSize](float f){
        
        //获取位置
        auto p=dot->getPosition();
        
        //小球触屏边后翻转
        if(p.x<0||p.x>visibleSize.width){
            _direction.x*=-1;
        }else if(p.y<0||p.y>visibleSize.height){
            _direction.y*=-1;
        }
        
        
        //当前的位置加上方向乘以10
        //当前的向量放大10倍
        dot->setPosition(p+_direction*10);
        
        
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





