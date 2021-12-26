# Queue
FIFO인 자료구조로 먼저 삽입된 데이터가 먼저 나오도록 배열로 구현하였다.

## time complexity
search : O(n)
insert : O(1)
delete : O(1)

## 회고
### linear_queue
1. queue가 empty, full인 상황을 결정해주는 것이 시간이 걸렸다.
- empty : back_ < front_인 상황
- full : back == N-1인 상황

2. front(), back() 에러 처리 아직 안함
- 가장 앞에 있는 원소를 반환해주는 front()함수는 queue에 원소가 없을 때 호출되면 에러처리를 해줘야 한다.
- 가장 뒤에 있는 원소를 반환해주는 back()함수는 queue에 원소가 없을 때 호출되면 에러처리를 해줘야 한다.

### circular_queue
empty : back_ == front_
full : (back_+1)%N == front_
할당 받은 모든 공간을 사용하면 empty와 full을 구분할 수 없게 된다.