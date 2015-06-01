//
//  StateOne.cpp
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "StateOne.h"
#include "StateTwo.h"
#include "Entity.h"
#include <iostream>

using namespace std;

void StateOne::exit(Entity* entity) {
    cout << "exit state 1 ." << endl;
}

void StateOne::enter(Entity* entity) {
    cout << "enter state 1 ." << endl;
}

void StateOne::execute(Entity* entity) {
    if(entity->Bar() >= 5) {
        entity->getFSM()->changeState(StateTwo::Instance());
    }
    else {
        cout << "state 1 ..." << endl;
    }
}

StateOne* StateOne::Instance() {
    static StateOne instance;
    return &instance;
}

bool StateOne::onMessage(Entity* entity, const Message& msg) {
    cout << "state 1 onMessage: " << msg.msg << endl;
    return true;
}
