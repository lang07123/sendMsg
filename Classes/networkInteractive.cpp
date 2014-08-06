//
//  networkInteractive.cpp
//  sendMsg
//
//  Created by lang7 on 14-7-10.
//
//

#include "networkInteractive.h"


USING_NS_CC;
USING_NS_CC_EXT;



bool networkInteractive::init()
{
    if (!Layer::init())
    {
        return false;
    }

    return true;
}

int networkInteractive::sendData(int protocolNum,const std::string& dataString)
{
 
    //accProtocolNum=100,
    //enemyProtocolNum=101,
    //getEnemy=102,
    //getUserCount=103
    
    printf("This is '%s' '%d' \n" ,dataString.c_str(),protocolNum);
    cocos2d::network::HttpRequest* request= new cocos2d::network::HttpRequest(); //创建容器
    
    protocolTypeReturn = protocolNum;
    
    if (protocolNum==accProtocolNum) {
        request->setUrl("http://127.0.0.1:8000/send/1/");
    }
    else if (protocolNum==enemyProtocolNum) {
        request->setUrl("http://127.0.0.1:8000/send/1/");
    }
    else if (protocolNum==getEnemy) {
        request->setUrl("http://127.0.0.1:8000/send/1/");
    }
    else if (protocolNum==getUserCount) {
        request->setUrl("http://127.0.0.1:8000/send/1/");
    }

    
    request->setRequestType(cocos2d::network::HttpRequest::Type::GET); //设定请求方式
    request->setResponseCallback(CC_CALLBACK_2(networkInteractive::onHttpRequestCompleted, this)); //设定回调函数
    request->setTag("getNetwork"); //设置 Tag
    cocos2d::network::HttpClient::getInstance()->send(request); //载入发送队列
    request->release(); //释放资源
    
    return 1;
}

void networkInteractive::onHttpRequestCompleted(cocos2d::network::HttpClient *sender,cocos2d::network::HttpResponse *response)
{
    
    if (!response->isSucceed())
    {
        

        errorString=response->getErrorBuffer();
        errorCode=response->getResponseCode();
        printf("Web Server Is Error String is %s",errorString.c_str());
        printf("Web Server Is Error code is %d",errorCode);
        
    }
    
    else
    {
        
        //accProtocolNum=100,
        //enemyProtocolNum=101,
        //getEnemy=102,
        //getUserCount=103
        
        errorCode=1;

        auto buffer=response->getResponseData();
        std::string reqStr;
    
        printf("Http Test,dump data:");
    
        for (int i=0; i < buffer->size(); i++)
        {
            reqStr+=(*buffer)[i];
        }
 
        printf("\nrequest String %s",reqStr.c_str());
        
    }
}

std::string networkInteractive::getRequestDataBuffer()
{
    return this->errorString;
}


int networkInteractive::getErrorCode()
{
    return this->errorCode;
}
