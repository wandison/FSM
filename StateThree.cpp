//
//  StateThree.cpp
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "StateThree.h"
#include "StateOne.h"
#include "Entity.h"
#include <iostream>

using namespace std;

void StateThree::exit(Entity* entity) {
    cout << "exit state 3 ." << endl;
}

void StateThree::enter(Entity* entity) {
    cout << "enter state 3 ." << endl;
}

void StateThree::execute(Entity* entity) {
    if(entity->Bar() >= 15) {
        entity->getFSM()->changeState(StateOne::Instance());
    }
    else {
        cout << "state 3 ..." << endl;
    }
}

StateThree* StateThree::Instance() {
    static StateThree instance;
    return &instance;
}