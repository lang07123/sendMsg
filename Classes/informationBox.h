//
//  informationBox.h
//  sendMsg
//
//  Created by lang7 on 14-7-14.
//
//

#ifndef __sendMsg__informationBox__
#define __sendMsg__informationBox__

#include "cocos2d.h"

class informationBox : public cocos2d::Layer
{
    
public:
    

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(informationBox);
    
    void initWithBackGroundLayer(const char *msgText);
    
    //virtual void registerWithTouchDispatcher();
    
    //bool ccTouchBegan(cocos2d::Touch *touch,cocos2d::Event *touchEvent);
    
    void yesButton(Ref * pRef);


private:
   
    //m_size
    cocos2d::Size * m_size;
    
    //控制精灵层
    cocos2d::Sprite *m_bgSprite;

    
};




#endif /* defined(__sendMsg__informationBox__) */
