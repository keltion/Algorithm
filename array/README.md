# array
array는 컴파일 시간에 고정 크기의 연속적인 메모리를 갖는다.

## time complexity
random access : O(1)  
search : O(n)  
insert : O(n)  
delete : O(n)  

## 회고
curly bases를 이용하여 array를 초기화하도록 구현하고 싶었다. 나름대로 생성자를 다양하게 만들어 봤지만 실패했다. 
이를 구현하기 위해서 gcc/libstdc++-v3/include/std/array의 코드의 constructor부분을 살펴보았다.

>  // No explicit construct/copy/destroy for aggregate type.

std::array는 aggregate type이기에 명시적인 constructor를 생성하지 않는다고 한다. 이것이 이해되지 않았고 다음의 글에서 이를 이해할 수 있었다.
https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special  
이 글은 위 사이트를 참고하여 작성하였다.

```cpp
MyArray<int, 4> arr = {1,2,3,4};
```
이러한 초기화는 array or aggregate class에만 허용된다고 한다. array는 aggregate이며 class는 다음 조건들을 만족하면 aggreagte가 될 수 있다.
1. No user-declared constructor
2. No private or protected non-static data members.
3. No base classes and no virtual functions
(An array is an aggregate even if it is an array of non-aggregate class type.)

### aggregates이 특별한 이유
```cpp
Type array_name[n] = {a1, a2, …, am};
```
They, unlike non-aggregate classes, can be initialized with curly braces {}.
if(m > n)인 상황에서 초기화는 어떻게 될까?
    - bool, int, pointers 등의 scalar type은 value-initialized 된다. element가 class type object이고 user-declared default constructor가 있다면 이 constructor로 인해 초기화가 되고, default constructor가 있다면 이것이 초기화를 진행한다.
(참조는 value-initalized될 수 없음.)

### Now let's see how aggregate classes can be initialized with braces
이는 우리가 c언어에서 array를 초기화하는 방식과 꽤 유사하다.
int arr[3] = {1,2,3};
우리는 위 코드에서 array의 원소 arr[0], arr[1], arr[2]는 각각 1, 2, 3 으로 초기화 됨을 알고있다.
```cpp
class AAA {// aggreate class
public:
    int a;
    double b;
    float c;
protected
    static d;
}
int main() {
    AAA aaa = {1,2.0, 3.0};
}
```
마찬가지로 위 코드는 AAA class의 non-static data member들의 정의 순서대로 aaa.a, aaa.b, aaa.c는 각각 1, 2.0, 3.0로 초기화된다.
만약 member의 수 보다 initializers의 수가 적다면 나머지 member들은 value-intialized된다. (The protected static member d is not initialized at all, because it is static.)

}

### why they are there.
If a user-defined constructor is present, it means that the user needs to do some extra work to initialize the members therefore brace initialization would be incorrect.
If virtual functions are present, it means that the objects of this class have (on most implementations) a pointer to the so-called vtable of the class, which is set in the constructor, so brace-initialization would be insufficient.


