from random import random
from typing import List
import random


class Solution:
    a = list()

    # def sum(self, w: List[int]) -> int:
    #     r = 0
    #     for i in w:
    #         r += i
    #     return r

    def __init__(self, w: List[int]):
        for idx in range(len(w)):
            curr = w[idx]
            for _ in range(curr):
                self.a.append(idx)

    def pickIndex(self) -> int:
        idx = random.randint(0, len(self.a) - 1)
        return self.a[idx]

if __name__ == '__main__':
    print("hello")

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
