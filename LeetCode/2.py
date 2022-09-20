import math
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def ListToListNode(l: Optional[list]):
    ln = ListNode(val = 0, next = None)
    prev = ln
    for e in l:
        next = ListNode(val = e, next = None)
        prev.next = next
        prev = next
    return ln.next

def ListNodeToList(ln: Optional[ListNode]):
    l = list()
    while ln is not None:
        l.append(ln.val)
        ln = ln.next
    return l

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = 0
        n2 = 0
        l1l = list()
        l2l = list()
        while l1 is not None:
            l1l.append(l1.val)
            l1 = l1.next
        while l2 is not None:
            l2l.append(l2.val)
            l2 = l2.next
        for i in range(len(l1l)):
            n1 *= 10
            n1 += l1l[len(l1l) - i - 1]
        for i in range(len(l2l)):
            n2 *= 10
            n2 += l2l[len(l2l) - i - 1]
        n3 = n1 + n2
        n3s = str(n3)[::-1]
        l3 = ListNode(val = 0, next = None)
        prevl3 = l3
        while n3s != "":
            nextl3 = ListNode(val = int(n3s[0]), next = None)
            prevl3.next = nextl3
            prevl3 = nextl3
            n3s = n3s[1:]
        if l3.next is None:
            return l3
        return l3.next

if __name__ == "__main__":
    s = Solution()
    r = s.addTwoNumbers(
        ListToListNode([1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]),
        ListToListNode([5, 6, 4])
    )
    print(ListNodeToList(r))
