


#include "Entity.h"

int main() {
    
    enum class EntityID {
        AAA,
        BBB
    };
    
    auto entity = new Entity(int(EntityID::AAA));
    
    // 观察效果
    for(int i = 0; i < 15; i++) {
        entity->update();
    }
    
    delete entity;
    
    return 0;
}
