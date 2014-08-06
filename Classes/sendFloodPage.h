//
//  sendFloodPage.h
//  sendMsg
//
//  Created by lang7 on 14-7-3.
//
//

#ifndef __sendMsg__sendFloodPage__
#define __sendMsg__sendFloodPage__




#include "config.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocos-ext.h"
#include "networkInteractive.h"
#include "informationBox.h"


USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d::extension;







class sendFloodPage : public cocos2d::Layer,public EditBoxDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(sendFloodPage);
    
    void initSendFloodPage();
    
    void goCheckPhoneNumber(Ref *pSen);

    EditBox *enemyEditBox;
    
    //输入委托事件
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);


    
    
private:
    


    
    
    
};



#endif /* defined(__sendMsg__sendFloodPage__) */
