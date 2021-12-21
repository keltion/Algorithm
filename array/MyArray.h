#include <iostream>

template<typename T, std::size_t N>
class MyArray{
public:
    T arr_[N];
    int ArraySearch(int value);
    void ArrayInsert(int value, int idx);
    void ArrayDelete(int idx);
    void ArrayPrint();
};

// No explicit construct/copy/destroy for aggregate type.

template<typename T, std::size_t N>
int MyArray<T,N>::ArraySearch(int value) {
    for(int i=0; i<N; i++) {
        if(arr_[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename T, std::size_t N>
void MyArray<T,N>::ArrayInsert(int idx, int value) {
    if(idx > N-1) {
        exit(0);
    }
    for(int i = N-1; i > idx; i--){
        arr_[i] = arr_[i-1];
    }
    arr_[idx] = value;
}

template<typename T, std::size_t N>
void MyArray<T,N>::ArrayDelete(int idx) {
    if(idx > N-1) {
        exit(0);
    }
    for(int i = idx; i < N-1; i++) {
        arr_[i] = arr_[i+1];
    }
    arr_[N-1] = 0;
}

template<typename T, std::size_t N>
void MyArray<T,N>::ArrayPrint() {
    for(int i=0; i <N; i++) {
        std::cout << arr_[i] << " ";
    }
    std::cout << std::endl;
    return;
}