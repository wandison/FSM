//
//  Message.h
//  ex1
//
//  Created by Buwenjie on 15-5-28.
//  Copyright (c) 2015年 Buwenjie. All rights reserved.
//

#ifndef ex1_Message_h
#define ex1_Message_h

#include <cmath>

struct Message {
    double dispatchTime;
    int id_sender;
    int id_receiver;
    int msg;
    void* extraInfo;
    
    Message() :
        dispatchTime(-1),
        id_sender(-1),
        id_receiver(-1),
        msg(-1),
        extraInfo(nullptr) {
        
    }
    
    Message(double dispatchTime, int sender, int receiver, int msg, void* extraInfo) {
        this->dispatchTime = dispatchTime;
        this->id_sender = sender;
        this->id_receiver = receiver;
        this->msg = msg;
        this->extraInfo = extraInfo;
    }
    
};

const double eps = 0.1;

inline bool operator== (const Message& m1, const Message& m2) {
    return (fabs(m1.dispatchTime - m2.dispatchTime) < eps) &&
        (m1.id_sender == m2.id_sender) &&
        (m1.id_receiver == m2.id_receiver) &&
        (m1.msg == m2.msg);
}

inline bool operator< (const Message& m1, const Message& m2) {
    return m1.dispatchTime < m2.dispatchTime;
}

template <typename T>
inline T DereferenceToType(void* p) {
    return *(T*)(p);
}

#endif
