//
//  EntityBase.cpp
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "EntityBase.h"
#include <cassert>

int EntityBase::_nextValidId = 0;

EntityBase::EntityBase(int pid) {
    setId(pid);
}

void EntityBase::setId(int pid) {
    assert(pid >= _nextValidId);
    
    _pid = pid;
    _nextValidId = pid + 1;
}

int EntityBase::Id() {
    return _pid;
}
