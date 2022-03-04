#include <iostream>
#include <memory>

#include "binary_search_tree.h"

int main() {
    std::unique_ptr<BinarySearchTree> bst = std::make_unique<BinarySearchTree>(50);
    bst->AddNode(51);
    bst->AddNode(52);
    bst->AddNode(53);
    bst->AddNode(54);
    bst->AddNode(55);
    bst->AddNode(56);

    if(bst->SearchNode(57)) {
        std::cout << "57 is in bst" << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }

    bst->print();
    
}