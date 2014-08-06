//
//  informationBox.cpp
//  sendMsg
//
//  Created by lang7 on 14-7-14.
//
//


#include "informationBox.h"

USING_NS_CC;


Scene* informationBox::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    informationBox *layer = informationBox::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool informationBox::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    return true;
}



void informationBox::initWithBackGroundLayer(const char *msgText)
{
    //获取窗口大小
    Size winSize = Director::getInstance()->getWinSize();
    
    //设置精灵背景图片
    Sprite * backGround =Sprite::create("messageBox.png");
    //Sprite * m_bgSprite = backGround;
    
    //设置位置
    backGround->setPosition(Point(winSize.width/2,winSize.height/2));
    
    backGround->setScale(1.3f);
    this->addChild(backGround,1);
    
    //获取长度
    Size contentSize =backGround->getContentSize();
    
    m_size = &contentSize;
    
    //创建确定按钮
    auto closeItem = MenuItemImage::create(
                                           "msgButton.png",
                                           "pressMsgButton.png",
                                           CC_CALLBACK_1(informationBox::yesButton,this));
    
    closeItem->setScale(0.15f);
    auto menu=Menu::create(closeItem,NULL);
    menu->alignItemsHorizontallyWithPadding(5);
    menu->setPosition(Point(contentSize.width-contentSize.width/3,contentSize.height/3));
    backGround->addChild(menu,2);
    
    //create error Msg
    auto msgLabel=Label::createWithBMFont("Heiti19.fnt",msgText);
    msgLabel->setPosition(Point(contentSize.width/2,contentSize.height/2));
    msgLabel->setAnchorPoint(Point::ANCHOR_MIDDLE);   //设置锚点居中
    //titleLabel->enableGlow(Color4B::BLUE);              //荧光颜色  描边和荧光只能设置在TTF上
    //msgLabel->setScale(2.2f);
    backGround->addChild(msgLabel,3);
    msgLabel->enableShadow(Color4B::BLUE,Size(1,-1),0.7); //1,颜色 2,阴影大小 3,透明度
    

}

void informationBox::yesButton(Ref * pRef)
{
    this->removeFromParentAndCleanup(true);
}
