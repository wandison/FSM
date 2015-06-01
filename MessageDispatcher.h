//
//  MessageDispatcher.h
//  ex1
//
//  Created by Buwenjie on 15-6-1.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__MessageDispatcher__
#define __ex1__MessageDispatcher__

#include <set>
#include "Message.h"
#include "EntityBase.h"

#define NO_ADDITIONAL_INFO nullptr
const double SEND_MSG_IMMEDIATELY = 0.0;

class MessageDispatcher {
public:
    static MessageDispatcher* Instance();
    void dispatchMessage(double delay, int sender, int receiver,
                         int msg, void* extraInfo);
    
    void dispatchDelayedMessages();
    
private:
    MessageDispatcher() {}
    std::set<Message> priorityQ;
    
    void discharge(EntityBase* reveicer, const Message& msg);
};

#endif /* defined(__ex1__MessageDispatcher__) */
