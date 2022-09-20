# SPOJ: CODESPTB

from typing import List, Tuple


def mergesort(to_sort: List[int]) -> Tuple[List[int], int]:
    n: int = len(to_sort)
    if n <= 1:
        return to_sort, 0
    mid: int = int(n / 2)
    left_part: List[int] = to_sort[0 : mid]
    right_part: List[int] = to_sort[mid : n]
    left_sorted, left_inv = mergesort(left_part)
    right_sorted, right_inv = mergesort(right_part)
    left_ptr: int = 0
    right_ptr: int = 0
    cross_inv: int = 0
    sorted: List[str] = list()
    while left_ptr < mid and right_ptr < n - mid:
        if left_sorted[left_ptr] <= right_sorted[right_ptr]:
            sorted.append(left_sorted[left_ptr])
            left_ptr += 1
        else:
            cross_inv += mid - left_ptr
            sorted.append(right_sorted[right_ptr])
            right_ptr += 1
    if len(sorted) < n:
        while left_ptr < mid:
            sorted.append(left_sorted[left_ptr])
            left_ptr += 1
        while right_ptr < n - mid:
            sorted.append(right_sorted[right_ptr])
            right_ptr += 1
    return sorted, left_inv + right_inv + cross_inv

if __name__ == "__main__":
    N: int = int(input())
    str_A: List[str] = input().split(" ")
    A: List[int] = list(int(x) for x in str_A)
    A_sorted, A_inv = mergesort(A)
    print(A_inv)
