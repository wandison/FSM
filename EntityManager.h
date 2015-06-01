//
//  EntityManager.h
//  ex1
//
//  Created by Buwenjie on 15-6-1.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__EntityManager__
#define __ex1__EntityManager__

#include <map>
#include "EntityBase.h"

class EntityManager {
public:
    static EntityManager* Instance();
    void registerEntity(EntityBase* entity);
    EntityBase* getEntityById(int pid);
    void removeEntity(EntityBase* entity);

private:
    EntityManager() {};
    std::map<int, EntityBase*> entityMap;
    
};

#endif /* defined(__ex1__EntityManager__) */
