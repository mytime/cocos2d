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

	/* Action 特效
	   使用Action特效，必须使用NodeGrid类来定义角色
	*/
  
   auto role = NodeGrid::create(); //创建一个角色  创建一个网格节点
   role->addChild(Sprite::create("role.png"));//指定角色图片
   role->setScale(0.5);
   role->setPosition(visibleSize/2);//角色位置：居中
   addChild(role);//把角色添加到当前场景中

   // 3D摇晃（Shaky3D）动作
   //
   // 用持续时间、网格大小、范围、是否在z轴摇晃等参数来创建一个Shaky3D动作。
   //role->runAction(Shaky3D::create(5,Size(50,50),5,false));
   //
   //ShakyTiles3D动作  这是一个让目标节点以多个瓦片的形式晃动的动作
   //参数：持续时间、网格大小、范围、是否在z轴摇晃
   //role->runAction(ShakyTiles3D::create(5, Size(50, 50), 5, false));
   //
   //ShuffleTiles 动作 这是一个让目标节点以多个瓦片的形式随机洗牌的动作
   //参数: 持续时间、网格大小,随机种子
   //role->runAction(ShuffleTiles::create(1, Size(50, 50), 5));


   //实现一个先抖动再爆炸的效果
   //auto shaky=ShakyTiles3D::create(1,Size(50,50),5,false);//抖动
   //auto shuffle = ShuffleTiles::create(0.5,Size(50,50),25);//爆炸
   //role->runAction(Sequence::create(shaky,shuffle,turn,NULL));//顺序动作（Sequnce）

   //碎片消失的效果 这是一个让目标节点以多个瓦片的形式随机关闭的动作
   //使用网格大小和持续时间创建动作。
   //role->runAction(TurnOffTiles::create(1,Size(50,50)));

   //Waves3D动作。
   //该动作用于在目标节点上制造3D波浪效果。 
   //你可以控制这些参数来影响效果 : 持续时间、网格大小、波浪的数量、振幅
   //auto w1 = Waves3D::create(2, Size(15, 10), 5, 40);
   //auto w2 = Waves3D::create(2, Size(15, 10), 5, 0);
   //role->runAction(Sequence::create(w1,w2,NULL));

   //PageTurn3D  翻页效果
   //使用持续时间，网格的大小创建一个动作。
   //role->runAction(PageTurn3D::create(2,Size(20,20)));

   //Liquid 液体效果
   //该动作用于在目标节点上制造液体效果。 你可以用这些参数定制特效: 持续时间、网格大小、波的数量、液体特效的振幅。
   role->runAction(Liquid::create(3,Size(30,30),5,10));



    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
