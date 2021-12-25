#pragma once

#include <array>
#include <iostream>

template<typename T, std::size_t N>
class queue {
public:
    queue();
    void push(T data);
    void pop();
    T front();
    T back();
    int size();
    bool empty();
private:
    std::array<T,N> arr;
    int front_;
    int back_;
};

template<typename T, std::size_t N>
queue<T, N>::queue(): front_{0}, back_{-1} {}

template<typename T, std::size_t N>
bool queue<T, N>::empty() {
    return (back_ < front_) ? true : false;
}

template<typename T, std::size_t N>
void queue<T, N>::push(T data) {
    if(back_== N-1) {
        std::cout << "ERROR: OVERFLOW!" << std::endl;
        exit(1);
    }
    back_++;
    arr[back_] = data;

}

template<typename T, std::size_t N>
void queue<T, N>::pop() {
    if(empty()) {
        std::cout << "There is no element!" << std::endl;
        exit(1);
    }
    front_++;
}

template<typename T, std::size_t N>
T queue<T, N>::front() {
    return arr[front_];
}

template<typename T, std::size_t N>
T queue<T, N>::back() {
    return arr[back_];
}

template<typename T, std::size_t N>
int queue<T, N>::size() {
    return back_ - front_ + 1;
}

