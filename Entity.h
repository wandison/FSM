//
//  Entity.h
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__Entity__
#define __ex1__Entity__

#include "EntityBase.h"
#include "FSM.hpp"

class Entity : public EntityBase {
public:
    Entity(int pid);
    ~Entity();
    
    void update() override;
    FSM<Entity>* getFSM();
    bool handleMessage(const Message& msg) override;
    
    int Bar();
    
private:
    FSM<Entity>* _fsm;
    
    //所有状态都是单例，所以数据不能存在状态中，要存在实体中
    //bar属性模拟一个驱动状态转换的属性
    int bar;
};

#endif /* defined(__ex1__Entity__) */
