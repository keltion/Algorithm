#include <iostream>
#include <typeinfo>

#include "MyArray.h"

int main() {
    int input;

    MyArray<int, 8> arr = {12, 32, 43, 12, 23, 42};
    arr.ArrayPrint();

    std::cin >> input;
    int answer = arr.ArraySearch(input);
    std::cout << "after ArraySearch: ";
    if(answer==-1) {
        std::cout << "doesn't exist"<< std::endl;
    }
    else {
        std::cout << "exist" << std::endl;
    }

    arr.ArrayInsert(4,4);
    std::cout << "after ArrayInsert: ";
    arr.ArrayPrint();

    arr.ArrayDelete(4);
    std::cout << "after ArrayDelete: ";
    arr.ArrayPrint();
}