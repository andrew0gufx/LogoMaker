//
// Created by 16177 on 2022/4/3.
//

#include "History.h"

std::stack<Snapshot> History::stack;

void History::pushHistory(const Snapshot& snapshot){
    stack.push(snapshot);
}


Snapshot History::topHistory(){
    if(stack.empty()){
        Snapshot temp("");
        return temp;
    }
    return stack.top();
}


void History::popHistory(){
    stack.pop();
}
