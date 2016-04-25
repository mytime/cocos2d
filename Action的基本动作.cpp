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

   auto role = Sprite::create("role.png");	//创建一个角色，图片资源需要放在resource目录下
   addChild(role);							//添加角色
   role->setPosition(visibleSize/2);		//显示位置
   role->setScale(0.3);						//缩放0.1倍

   role->setPositionX(100);
   /*简单的Action，2秒内X轴向右移动100像素*/
   //role->runAction(MoveTo::create(2,Vec2(visibleSize.width-100,visibleSize.height/2)));

   


   /*顺序动作（Sequnce）可以顺序得一个接着一个运行内部动作序列 */
   //auto move1=MoveTo::create(2,Vec2(visibleSize.width-100,visibleSize.height/2));
   //auto move2=MoveBy::create(2,Vec2(-1000,0));
   //role->runAction(Sequence::create(move1,move2,NULL));




	/*反转动作 */
	//用持续时间和位移创建MoveBy动作
	//Vec2(X轴,Y轴)
	//auto move3=MoveBy::create(2,Vec2(1000,0));
	//auto move4 = move3->reverse(); //执行与原动作完全相反的动作
	//role->runAction(Sequence::create(move3, move4, NULL));



	/*并列动作*/
	//移动action
	auto move = MoveBy::create(2,Vec2(500,0));

	//缩放action ScaleTo *create (float duration, float s)
	//用持续时间和X和Y轴相同的缩放比例创建ScaleTo动作
	//参数：
	//duration	持续时间，以秒为单位。
	//s	X和Y轴的缩放比例。
	//返回:  一个自释放的ScaleTo对象。 
	auto scale = ScaleTo::create(2,1);
	//role->runAction(Spawn::create(move,scale,NULL));//用一个给定数组创建一个Spawn动作。

	//用一个回调函数创建CallFunc动作，回调函数的类型是std::function<void()>
	role->runAction(Sequence::create(Spawn::create(move,scale,NULL),CallFunc::create([](){
		//回调内容
		CCLOG("Play completed");
	}),NULL));


    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
