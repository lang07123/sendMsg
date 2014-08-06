//
//  networkInteractive.h
//  sendMsg
//
//  Created by lang7 on 14-7-10.
//
//

#ifndef __sendMsg__networkInteractive__
#define __sendMsg__networkInteractive__

#include <string>
#include "config.h"
#include "cocos2d.h"
#include "HttpRequest.h"
#include "HttpClient.h"
#include "HttpResponse.h"
#include "cocos-ext.h"
#include "HelloWorldScene.h"


class networkInteractive :public cocos2d::Layer
{
    
public:
    
    
    virtual bool init();
    
    CREATE_FUNC(networkInteractive);
    
    
    int sendData(int protocolNum,const std::string& dataString);
    void onHttpRequestCompleted(cocos2d::network::HttpClient *sender,cocos2d::network::HttpResponse *response);
    
    std::string getRequestDataBuffer();
    int getErrorCode();

    
private:
    
    int protocolTypeReturn;
    std::string errorString;
    int errorCode;
    
    
};


#endif /* defined(__sendMsg__networkInteractive__) */
