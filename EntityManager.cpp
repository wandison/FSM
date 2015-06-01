//
//  EntityManager.cpp
//  ex1
//
//  Created by Buwenjie on 15-6-1.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#include "EntityManager.h"
#include <cassert>

EntityManager* EntityManager::Instance() {
    static EntityManager instance;
    return &instance;
}

void EntityManager::registerEntity(EntityBase* entity) {
    entityMap.insert(std::make_pair(entity->Id(), entity));
}

EntityBase* EntityManager::getEntityById(int pid) {
    auto res = entityMap.find(pid);
    
    assert(res != entityMap.end());
    
    return res->second;
}

void EntityManager::removeEntity(EntityBase* entity) {
    entityMap.erase(entityMap.find(entity->Id()));
}
