//
// Created by 16177 on 2022/4/3.
//

#ifndef SFML_PROJECT_SNAPSHOT_H
#define SFML_PROJECT_SNAPSHOT_H
#include <iostream>

class Snapshot{
public:
    Snapshot(std::string data = "");
    std::string getData() const;
    void setString(std::string other);

private:
    std::string data;
};


#endif //SFML_PROJECT_SNAPSHOT_H
