from typing import List

def check(DiffStalls: List[int], distance: int, cows: int) -> bool:
    fitted: int = 1
    thisInterval: int = distance
    for diffStall in DiffStalls:
        if thisInterval <= 0:
            fitted += 1
            if fitted >= cows:
                return True
            thisInterval = distance
        thisInterval -= diffStall
    if thisInterval <= 0:
        fitted += 1
    if fitted >= cows:
        return True
    return False

if __name__ == "__main__":
    T: int = int(input())
    while T > 0:
        T -= 1
        secondLine: List[int] = list(int(x) for x in input().split(" "))
        N: int = secondLine[0]
        C: int = secondLine[1]
        Stalls: List[int] = list()
        while N > 0:
            N -= 1
            Stalls.append(int(input()))
        Stalls.sort()
        DiffStalls: List[int] = list()
        last: int = -1
        for stall in Stalls:
            if last == -1:
                diff = 0
            else:
                diff = stall - last
            last = stall
            DiffStalls.append(diff)
        low: int = 0
        high: int = 1000000000
        while True:
            mid: int = int((low + high) / 2)
            if low == mid:
                break
            if check(DiffStalls, mid, C):
                low = mid
            else:
                high = mid
        print(low)
