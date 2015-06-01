//
//  MessageDispatcher.cpp
//  ex1
//
//  Created by Buwenjie on 15-6-1.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "MessageDispatcher.h"
#include "EntityManager.h"
#include <ctime>

MessageDispatcher* MessageDispatcher::Instance() {
    static MessageDispatcher instance;
    return &instance;
}

void MessageDispatcher::dispatchMessage(double delay, int sender, int receiver,
                     int msg, void* extraInfo) {
    Message message(0, sender, receiver, msg, extraInfo);
    EntityBase* p_receiver = EntityManager::Instance()->getEntityById(receiver);
    if(delay <= 0) {
        discharge(p_receiver, message);
    }
    else {
        auto currentTime = time(nullptr);
        message.dispatchTime = currentTime + delay;
        priorityQ.insert(message);
    }
}

void MessageDispatcher::dispatchDelayedMessages() {
    auto currentTime = time(nullptr);
    while(!priorityQ.empty() && priorityQ.begin()->dispatchTime <= currentTime) {
        auto& message = *priorityQ.begin();
        auto receiver = EntityManager::Instance()->getEntityById(message.id_receiver);
        discharge(receiver, message);
        priorityQ.erase(priorityQ.begin());
    }
}

void MessageDispatcher::discharge(EntityBase* reveicer, const Message& msg) {
    reveicer->handleMessage(msg);
}
