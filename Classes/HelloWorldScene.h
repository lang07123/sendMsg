#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "config.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "sendFloodPage.h"
#include "networkInteractive.h"
#include "informationBox.h"


USING_NS_CC;
USING_NS_CC_EXT;

using namespace ui;
using namespace cocos2d::extension;



class HelloWorld : public cocos2d::Layer ,public EditBoxDelegate
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void goCheckNumber(Ref* pSender);
    void startFloodPage();
    void getResponseDataComplete();//int getCode,const std::string text);
    

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
    //输入委托事件
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);

private:
    
    EditBox *accountEditbox;
    EditBox *passwdEditbox;
    int getErrorCode;

  
    
    
};

#endif // __HELLOWORLD_SCENE_H__
