//
// Created by 16177 on 2022/4/3.
//

#include "SnapShot.h"
Snapshot::Snapshot(std::string data){
    this->data = data;
}


std::string Snapshot::getData() const{
    return data;
}

void Snapshot::setString(std::string other){
    data = other;
}