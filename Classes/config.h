//
//  config.h
//  sendMsg
//
//  Created by lang7 on 14-7-19.
//
//

#ifndef sendMsg_config_h
#define sendMsg_config_h

#include "cocos2d.h"

typedef enum{
    
    accountEditTagNum=11,
    passwdEditTagNum=12,
    enemyEditTagNum=13,
    
}editBoxTagNUM ;

typedef enum{
    
    accProtocolNum=100,
    enemyProtocolNum=101,
    getEnemy=102,
    getUserCount=103,
    
}protocolItem ;

typedef enum{
    
    accProtocolItemTag=150,
    enemyProtocolItemTag=151,
    getEnemyItemTag=152,
    getUserCountItemTag=153,
    errorRequestTag=154,
    
}networkRequestItem ;



#endif
