#include <iostream>
#include "queue.h"
#include <string>

int main() {
    queue<std::string, 3> catNameQueue;
    
    catNameQueue.push("nabi");
    catNameQueue.pop();
    catNameQueue.push("tobu");
    catNameQueue.pop();
    catNameQueue.push("happy");
    catNameQueue.pop();
    catNameQueue.push("bori");
    
}