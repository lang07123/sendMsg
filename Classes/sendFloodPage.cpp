//
//  sendFloodPage.cpp
//  sendMsg
//
//  Created by lang7 on 14-7-3.
//
//

#include "sendFloodPage.h"
#include "cocos2d.h"

USING_NS_CC;


Scene* sendFloodPage::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    sendFloodPage *layer = sendFloodPage::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool sendFloodPage::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    return true;
    
}

void sendFloodPage::initSendFloodPage()
{
    
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //set allEditPointBase
    
    auto editPointBaseX=visibleSize.width/9;
    auto editPointBaseY=visibleSize.height-visibleSize.height/2+100;

    
    //create plistSprite
    
    //SpriteFrameCache * sendFrameCache=SpriteFrameCache::getInstance();
    //sendFrameCache->addSpriteFramesWithFile("sendMsgLogin0.plist");
    //sendFrameCache->autorelease();
    
    Sprite *PageBackGround = Sprite::create("psd867121.png");
    //Sprite *PageBackGround = Sprite::createWithSpriteFrameName("psd867121.png");

    
    if(!PageBackGround)
    {
        log("PagebackGroud %p",PageBackGround);
    }
    
    PageBackGround->setPosition(Point(0,0));      //设置图片位置
    PageBackGround->setScale(4.0f);               //设置图片缩放大小
    PageBackGround->setAnchorPoint(Point(Point::ZERO));   //设置图片锚点
    this->addChild(PageBackGround,1);
    
    
    //create enemyEditBoxBackGround
    
    Sprite *enemyEditBoxBackGround=Sprite::create("editBox.png");
    enemyEditBoxBackGround->setPosition(editPointBaseX,editPointBaseY);
    enemyEditBoxBackGround->setAnchorPoint(Point(0,0));
    enemyEditBoxBackGround->setScale(2.0f);
    this->addChild(enemyEditBoxBackGround,3);
    
    
    //create enemyEditBox
    
    enemyEditBox = EditBox::create(Size(500,60),Scale9Sprite::create());
    enemyEditBox->setPosition(Point(editPointBaseX+20,editPointBaseY+32));
    enemyEditBox->setPlaceHolder("plase enter your enemy .");
    enemyEditBox->setFontColor(Color3B::BLACK);
    enemyEditBox->setAnchorPoint(Point(0,0));
    enemyEditBox->setInputMode(EditBox::InputMode::NUMERIC);  //设置键盘输入类型
    enemyEditBox->setReturnType(EditBox::KeyboardReturnType::DONE); //设置键盘回车键类型
    enemyEditBox->setDelegate(this);
    enemyEditBox->setMaxLength(11);
    enemyEditBox->setTag(enemyEditTagNum);
    this->addChild(enemyEditBox,3);
    
    //create checkButton
    
    auto closeItem = MenuItemImage::create(
                                           "goButon.png",
                                           "pressButon.png",
                                           CC_CALLBACK_1(sendFloodPage::goCheckPhoneNumber,this));
    
    closeItem->setPosition(Point(editPointBaseX+125,editPointBaseY-450));
    closeItem->setAnchorPoint(Point(0,0));
    closeItem->setScale(0.6f);
    auto menu=Menu::create(closeItem,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,2);

    //create titleLabel
    
    auto titleLabel=Label::createWithBMFont("Heiti19.fnt","attack_Flood");
    titleLabel->setPosition(Point(editPointBaseX+240,editPointBaseY+280));
    titleLabel->setAnchorPoint(Point::ANCHOR_MIDDLE);   //设置锚点居中
    //titleLabel->enableGlow(Color4B::BLUE);              //荧光颜色  描边和荧光只能设置在TTF上
    titleLabel->setScale(2.2f);
    this->addChild(titleLabel,3);
    titleLabel->enableShadow(Color4B(128,180,89,255),Size(5,-5),0.7); //1,颜色 2,阴影大小 3,透明度
    
}


void sendFloodPage::goCheckPhoneNumber(Ref *pSen)
{
    log("strat go CheckPhoneNumber ...../n");
    
    //auto attackPerameterEditbox = (EditBox*)this->getChildByTag(enemyEditTagNum); //根据tag获取EditBox
    auto phoneNumberTemp = enemyEditBox->getText();
    
    //判断电话号码是否输入正常
    if (strlen(phoneNumberTemp)!=11) {
        informationBox *popBox=informationBox::create();
        popBox->initWithBackGroundLayer("Phone Number Error!");
        this->addChild(popBox,4);
    }
    else
    {
        log("ladkfsaldkf  %s",phoneNumberTemp);
    }
    
}


//editBox 开始输入委托
void sendFloodPage::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidBegin !", editBox);
}

//editBox 输入结束委托
void sendFloodPage::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidEnd !", editBox);
    auto editBoxStr=editBox->getText();
    
    //判断输入长度
    if (strlen(editBoxStr)<11) {
        log("The phone number error editBoxEditingDidEnd");

    }
    
}

//editBox 改变委托
void sendFloodPage::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
    log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

//editBox 点击非输入框委托
void sendFloodPage::editBoxReturn(EditBox* editBox)
{
    
    log("editBox %p was returned !",editBox);
    
}