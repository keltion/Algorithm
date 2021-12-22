#include <iostream>
#include "queue.h"
#include <string>

int main() {
    queue<std::string, 4> catNameQueue;
    
    catNameQueue.push("nabi");
    catNameQueue.push("tobu");
    catNameQueue.push("happy");
    
    catNameQueue.pop();
    catNameQueue.pop();
    catNameQueue.pop();
    
    if(!catNameQueue.empty()) {
        std::cout<< catNameQueue.front() << std::endl;
    }

    catNameQueue.push("bombi");
    catNameQueue.push("cheese");
    catNameQueue.push("nabi");
    catNameQueue.push("tobu");

}