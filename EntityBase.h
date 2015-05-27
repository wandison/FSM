//
//  EntityBase.h
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__EntityBase__
#define __ex1__EntityBase__

class EntityBase {
public:
    EntityBase(int pid);
    
    void setId(int pid);
    int Id();
    
    virtual void update() = 0;
    
    virtual ~EntityBase() {};
    
private:
    int _pid;
    static int _nextValidId;
};

#endif /* defined(__ex1__EntityBase__) */
