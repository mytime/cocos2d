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
	//文件读写

	
	auto fu = FileUtils::getInstance();//获取FileUtils的实例。 

	//写出
	//fullPathFromRelativeFile 从一个文件名和相对的路径文件得到完整路径。 
	//getWritablePath 获取可写的路径
/*	FILE *f = fopen(fu->fullPathFromRelativeFile("data.txt",fu->getWritablePath()).c_str(),"w");
	fprintf(f,"Hello yanwanfu\n");//写入内容	
	fclose(f);//关闭文件
*/

	//log("%s",fu->getWritablePath().c_str());
	//返回路径： C:/Users/Administrator/AppData/Local/HelloWorld/


	//读入
	Data d = fu->getDataFromFile(fu->fullPathFromRelativeFile("data.txt",
		fu->getWritablePath()));
	log("%s",d.getBytes());
	
	

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
