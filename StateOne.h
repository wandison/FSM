//
//  StateOne.h
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__StateOne__
#define __ex1__StateOne__

#include "State.h"

class Entity;

class StateOne : public State<Entity> {
public:
    static StateOne* Instance();
    
    void exit(Entity* entity) override;
    void enter(Entity* entity) override;
    void execute(Entity* entity) override;
};

#endif /* defined(__ex1__StateOne__) */
