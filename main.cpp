


#include "Entity.h"
#include "EntityManager.h"
#include "MessageTypes.h"
#include "MessageDispatcher.h"

#include <string>
#include <iostream>

int main() {
    
    enum class EntityID {
        AAA,
        BBB
    };
    
    auto entity = new Entity(int(EntityID::AAA));
    EntityManager::Instance()->registerEntity(entity);
    
    // 观察效果
    for(int i = 0; i < 15; i++) {
        entity->update();
        MessageDispatcher::Instance()->dispatchMessage(SEND_MSG_IMMEDIATELY,
                                                       int(EntityID::BBB),
                                                       int(EntityID::AAA),
                                                       int(MessageTypes::MSG_ONE),
                                                       NO_ADDITIONAL_INFO);
    }
    
    delete entity;
    
    return 0;
}
