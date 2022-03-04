# 이진 탐색 트리(BST)
## 개요
자식노드가 최대 두 개인 노드들로 구성된 이진트리에 이분하는 규칙을 추가한 트리를 BST라고 합니다. 그 규칙은 다음과 같습니다.
1. 왼쪽 자식 < 부모
2. 오른쪽 자식 > 부모

## BST의 time complexity
### 평균
- 탐색 시간: O(logn)
노드를 지날 때마다 크기를 비교하며 비교할 노드의 개수를 계속 반으로 줄여가므로 O(logn)의 시간복잡도를 가집니다.

- 삽입 시간: O(logn)
데이터 추가 시 정렬된 상태를 유지하며 삽입해야 합니다. 이를 위해서 '탐색'을 해야하고 삽입될 자리를 찾은 이후에 O(1)의 시간복잡도가 걸리므로 총 O(logn)의 시간복잡도를 가집니다.

- 삭제 시간: O(logn)
삭제할 노드를 탐색하는 시간과 이 노드 대신 삭제할 리프노드를 탐색하는 시간은 O(logn)이며 노드를 복사하는 시간이 O(1), 리프 노드를 삭제하는 시간이 O(1) 이므로 총 O(logn)의 시간복잡도를 가집니다.

### 최악
- 탐색, 삽입, 삭제 시간: O(n)
링크드리스트처럼 자식노드들이 한쪽으로만 이뤄져있는 경우를 생각하면 이해하기 쉽습니다.

## 정렬된 배열과의 비교
정렬된 배열
- 보통 이진 탐색 전에 정렬을 함 
-> 삽입/삭제 할때마다 정렬할 수도 있음
- 새로 추가된 데이터는 비정렬 상태
- (일단 정렬 후) 탐색 시간: O(logn)
- 삽입 및 삭제 : O(n)
- 매우 간단한 데이터 구조
- 메모리 한 덩어리

이진 탐색 트리
- 탐색 전에 따로 정렬 불필요
- 데이터 추가 시 정렬된 위치에 추가
- 탐색 시간 O(logn)
- 평균 삽입/삭제 시간: O(logn)
- 연결 리스트 이상 복잡한 데이터 구조
- 보통 여러 메모리 덩어리

(출처-포큐아카데미)

## 관련 문제
leetcode 98