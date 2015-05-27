//
//  State.h
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__State__
#define __ex1__State__

template <typename T>
class State {
public:
    virtual ~State() {};
    
    virtual void exit(T* entity) {};
    virtual void enter(T* entity) {};
    virtual void execute(T* entity) = 0;
};

#endif /* defined(__ex1__State__) */
