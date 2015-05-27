//
//  Entity.cpp
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "Entity.h"
#include "StateOne.h"

Entity::Entity(int pid) : EntityBase(pid) {
    _fsm = new FSM<Entity>(this);
    _fsm->setCurrentState(StateOne::Instance());
    
    //初始化bar
    bar = 0;
}

Entity::~Entity() {
    delete _fsm;
}

void Entity::update() {
    bar += 1;
    _fsm->update();
}

FSM<Entity>* Entity::getFSM() {
    return _fsm;
}

int Entity::Bar() {
    return bar;
}