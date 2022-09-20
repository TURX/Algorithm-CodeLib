from typing import List, Tuple


def merge(left_sorted: List[int], right_sorted: List[int]):
    left_ptr: int = 0
    right_ptr: int = 0
    cross_inv: int = 0
    sorted: List[int] = list()
    while left_ptr < len(left_sorted) and right_ptr < len(right_sorted):
        if left_sorted[left_ptr] > right_sorted[right_ptr]:
            cross_inv += len(left_sorted) - left_ptr
            sorted.append(right_sorted[right_ptr])
            right_ptr += 1
        else:
            sorted.append(left_sorted[left_ptr])
            left_ptr += 1
    while left_ptr < len(left_sorted):
        sorted.append(left_sorted[left_ptr])
        left_ptr += 1
    while right_ptr < len(right_sorted):
        sorted.append(right_sorted[right_ptr])
        right_ptr += 1
    return cross_inv, sorted


def mergesort(to_sort: List[int]) -> Tuple[int, List[int], List[int]]:
    n: int = len(to_sort)
    if n <= 1:
        return 0, to_sort, to_sort
    mid: int = int(n / 2)
    left_arr: List[int] = to_sort[0: mid]
    right_arr: List[int] = to_sort[mid: n]
    left_inv, left_sorted, left_tree = mergesort(left_arr)
    right_inv, right_sorted, right_tree = mergesort(right_arr)
    cross_inv_lr, sorted = merge(left_sorted, right_sorted)
    cross_inv_rl, _ = merge(right_sorted, left_sorted)
    if cross_inv_lr < cross_inv_rl:
        tree = left_tree + right_tree
    else:
        tree = right_tree + left_tree
    inv = left_inv + right_inv + min(cross_inv_lr, cross_inv_rl)
    return inv, sorted, tree


if __name__ == "__main__":
    A: List[int] = list(int(x) for x in input().split(" "))
    inv, sorted, tree = mergesort(A)
    print("inv:", inv)
    print("sorted:", sorted)
    print("tree:", tree)
