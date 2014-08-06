#include "HelloWorldScene.h"
#include "cocos-ext.h"


#include "platform/CCGLViewProtocol.h"

USING_NS_CC;
USING_NS_CC_EXT;    //editbox命名空间


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
    Point origin =Director::getInstance()->getVisibleOrigin();

    
    //Create TouchListener on untextrange
    //auto listenerAll=EventListenerTouchOneByOne::create(); //创建监听
    //listenerAll->setSwallowTouches(true);//触摸是否传递到下层
    //Rect allTouceRect＝Rect(0, 0, visibleSize.width, visibleSize.height);
    //listenerAll->onTouchBegan = CC_CALLBACK_2(HelloWorld::allToucheLintenerBegan, this);

    
    //create plistSprite
    
    SpriteFrameCache * frameCache=SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("sendMsgLogin0.plist");
    frameCache->autorelease();

    
    //create backGround
    
    Sprite *backGround = Sprite::createWithSpriteFrameName("psd867121.png");
    backGround->setPosition(Point(0,0));      //设置图片位置
    backGround->setScale(4.0f);               //设置图片缩放大小
    backGround->setAnchorPoint(Point(Point::ZERO));   //设置图片锚点
    this->addChild(backGround,1);
 
    
    //set allEditPointBase
    
    auto editPointBaseX=visibleSize.width/9;
    auto editPointBaseY=visibleSize.height-visibleSize.height/2+100;
    
    
    //create accountEditBoxBackGround

    Sprite *accountEditBackGround=Sprite::createWithSpriteFrameName("editBox.png");
    accountEditBackGround->setPosition(editPointBaseX,editPointBaseY);
    accountEditBackGround->setAnchorPoint(Point(0,0));
    accountEditBackGround->setScale(2.0f);
    this->addChild(accountEditBackGround,3);

    
    //create AccountEditBox

    accountEditbox = EditBox::create(Size(500,60),Scale9Sprite::create());
    accountEditbox->setPosition(Point(editPointBaseX+20,editPointBaseY+32));
    accountEditbox->setPlaceHolder("plase enter your number .");
    accountEditbox->setFontColor(Color3B::BLACK);
    accountEditbox->setAnchorPoint(Point(0,0));
    accountEditbox->setInputMode(EditBox::InputMode::EMAIL_ADDRESS);  //设置键盘输入类型
    accountEditbox->setReturnType(EditBox::KeyboardReturnType::DONE); //设置键盘回车键类型
    accountEditbox->setDelegate(this);
    accountEditbox->setTag(accountEditTagNum);
    this->addChild(accountEditbox,3);

    
    //create passwdEditBoxBackGround
    
    Sprite *passwdEditBackGround=Sprite::createWithSpriteFrameName("editBox.png");
    passwdEditBackGround->setPosition(editPointBaseX,editPointBaseY-150);
    passwdEditBackGround->setAnchorPoint(Point(0,0));
    passwdEditBackGround->setScale(2.0f);
    this->addChild(passwdEditBackGround,3);
    
    
    //create passwdEditbox
    
    passwdEditbox = EditBox::create(Size(500,60),Scale9Sprite::create());
    passwdEditbox->setPosition(Point(editPointBaseX+20,editPointBaseY-150+32));
    passwdEditbox->setPlaceHolder("plase enter your passwd .");
    passwdEditbox->setFontColor(Color3B::BLACK);
    passwdEditbox->setInputFlag(EditBox::InputFlag::PASSWORD);
    passwdEditbox->setReturnType(EditBox::KeyboardReturnType::DONE);
    passwdEditbox->setAnchorPoint(Point(0,0));
    passwdEditbox->setTag(passwdEditTagNum);
    this->addChild(passwdEditbox,3);
    
    
    //create checkButton
    
    auto closeItem = MenuItemImage::create(
                                           "goButon.png",
                                           "pressButon.png",
                                           CC_CALLBACK_1(HelloWorld::goCheckNumber,this));
    
    closeItem->setPosition(Point(editPointBaseX+125,editPointBaseY-450));
    closeItem->setAnchorPoint(Point(0,0));
    closeItem->setScale(0.6f);
    auto menu=Menu::create(closeItem,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,2);
    
    //create titleLabel
    
    auto titleLabel=Label::createWithBMFont("Heiti19.fnt","sendMsg_Flood");
    titleLabel->setPosition(Point(editPointBaseX+240,editPointBaseY+280));
    titleLabel->setAnchorPoint(Point::ANCHOR_MIDDLE);   //设置锚点居中
    //titleLabel->enableGlow(Color4B::BLUE);              //荧光颜色  描边和荧光只能设置在TTF上
    titleLabel->setScale(2.2f);
    this->addChild(titleLabel,3);
    titleLabel->enableShadow(Color4B(86,150,220,255),Size(5,-5),0.7); //1,颜色 2,阴影大小 3,透明度
    

    return true;
}

void HelloWorld::goCheckNumber(Ref* pSender)
{
    
    //灵魂一样的代码。。终于解决了。狗日的。
    //auto accPerameterEditbox = (EditBox*)this->getChildByTag(accountEditTagNum); //根据tag获取EditBox
    //auto accPerameterEditboxText = accPerameterEditbox->getText();
    
    auto accPerameterEditboxText =accountEditbox->getText();
    log("this is acc compelet %s \n",accPerameterEditboxText);
    
    // get passwdText
    auto passwdPerameterEditboxText = passwdEditbox->getText();
    log("this is passwd compelet %s \n",passwdPerameterEditboxText);
 
    networkInteractive *netWorkGet=networkInteractive::create();
    
    getErrorCode=netWorkGet->sendData(100,accPerameterEditboxText);
    //getErrorCode=netWorkGet->getErrorCode();
    
    printf("error Code : %d \n",getErrorCode);
    
    //netWorkGet->autorelease();
    
    //printf("this is connect last .%s",errorCodeGlobal.c_str());
    
    
    
        
    auto checkFlag=1;
    if (1==checkFlag)
    {
        
        HelloWorld::startFloodPage();
        
    }
    else
    {
        
        log("failed__%d",checkFlag);
        
    }

}

void HelloWorld::getResponseDataComplete()//int getCode,const std::string text)
{

    log("go in getResponseDataComplet");

}


void HelloWorld::startFloodPage()
{
    
    Scene *startFlood=Scene::create();
    sendFloodPage *sendFloodPageLayer=sendFloodPage::create();
    
    startFlood->addChild(sendFloodPageLayer);
    sendFloodPageLayer->initSendFloodPage();
    
    Director::getInstance()->replaceScene(TransitionFade::create(1.2f, startFlood, Color3B(218,216,217)));
    
}



//editBox 输入委托
void HelloWorld::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidBegin !", editBox);
}

//editBox 输入结束委托
void HelloWorld::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidEnd !", editBox);
}

//editBox 改变委托
void HelloWorld::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
    log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

//editBox 点击非输入框委托
void HelloWorld::editBoxReturn(EditBox* editBox)
{
    log("editBox %p was returned !",editBox);
    
    if (accountEditbox == editBox)
    {
        log("Name EditBox return !");
    }
    else if (passwdEditbox == editBox)
    {
        log("Password EditBox return !");
    }
}

