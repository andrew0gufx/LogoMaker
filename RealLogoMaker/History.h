//
// Created by 16177 on 2022/4/3.
//

#ifndef SFML_PROJECT_HISTORY_H
#define SFML_PROJECT_HISTORY_H
#include <map>
#include <stack>
#include "GUIComponent.h"

class History{

private:
    static std::stack<Snapshot> stack;
public:
    static void pushHistory(const Snapshot& snapshot);
    static Snapshot topHistory();
    static void popHistory();

};


#endif //SFML_PROJECT_HISTORY_H
