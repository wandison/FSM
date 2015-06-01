//
//  StateThree.h
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__StateThree__
#define __ex1__StateThree__

#include "State.h"

class Entity;

class StateThree : public State<Entity> {
public:
    static StateThree* Instance();
    
    void exit(Entity* entity) override;
    void enter(Entity* entity) override;
    void execute(Entity* entity) override;
    
    bool onMessage(Entity* entity, const Message& msg) override;
};

#endif /* defined(__ex1__StateThree__) */
