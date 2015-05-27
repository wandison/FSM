//
//  StateTwo.cpp
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "StateTwo.h"
#include "StateThree.h"
#include "Entity.h"
#include <iostream>

using namespace std;

void StateTwo::exit(Entity* entity) {
    cout << "exit state 2 ." << endl;
}

void StateTwo::enter(Entity* entity) {
    cout << "enter state 2 ." << endl;
}

void StateTwo::execute(Entity* entity) {
    if(entity->Bar() >= 10) {
        entity->getFSM()->changeState(StateThree::Instance());
    }
    else {
        cout << "state 2 ..." << endl;
    }
}

StateTwo* StateTwo::Instance() {
    static StateTwo instance;
    return &instance;
}
