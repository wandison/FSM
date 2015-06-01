//
//  FSM.h
//  ex1
//
//  Created by Buwenjie on 15-5-27.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef __ex1__FSM__
#define __ex1__FSM__

#include "State.h"
#include <cassert>
#include <typeinfo>
#include "Message.h"

template <typename T>
class FSM {
public:
    FSM(T* owner)
        : _owner(owner),
        _previousState(nullptr),
        _currentState(nullptr),
        _globalState(nullptr) {
        
    }
    
    void update() {
        if(_currentState) _currentState->execute(_owner);
        if(_globalState) _globalState->execute(_owner);
    }
    
    void changeState(State<T>* newState) {
        assert(newState);
        
        _previousState = _currentState;
        _currentState->exit(_owner);
        _currentState = newState;
        _currentState->enter(_owner);
    }
    
    void revertToPreviousState() {
        changeState(_previousState);
    }
    
    // 设置状态
    void setPreviousState(State<T>* state) {_previousState = state;}
    void setCurrentState(State<T>* state) {_currentState = state;}
    void setGlobalState(State<T>* state) {_globalState = state;}
    
    // 获取状态
    State<T>* PreviousState() {return _previousState;}
    State<T>* CurrentState() {return _currentState;}
    State<T>* GlobalState() {return _globalState;}
    
    bool isInState(const State<T>* state) {
        return typeid(*_currentState) == typeid(*state);
    }

    bool handleMessage(const Message& msg) {
        if(_currentState && _currentState->onMessage(_owner, msg)) {
            return true;
        }
        // 如果当前状态不能处理，交给全局状态处理
        if(_globalState && _globalState->onMessage(_owner, msg)) {
            return true;
        }
        return false;
    }
    
private:
    T* _owner;
    
    State<T>* _previousState;
    State<T>* _currentState;
    State<T>* _globalState;
};

#endif /* defined(__ex1__FSM__) */
