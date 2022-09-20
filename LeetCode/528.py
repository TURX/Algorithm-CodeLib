from typing import List
import random

class Solution:
	def __init__(self, w: List[int]):
		self.prefixes = list()
		prefix = 0
		for i in w:
			prefix += i
			self.prefixes.append(prefix)

	def getSum(self, leftIdx: int, rightIdx: int) -> int:
		leftIdx -= 1
		rightIdx -= 1
		if leftIdx < 0:
			return self.prefixes[rightIdx]
		else:
			return self.prefixes[rightIdx] - self.prefixes[leftIdx]
	
	def inRight(self, leftProb: float, rightProb: float) -> bool:
		probSum = leftProb + rightProb
		normalizedLeftProb = leftProb / probSum
		rand = random.random()
		return rand > normalizedLeftProb

	def pickIndexInInterval(self, startIndex: int, endIndex: int) -> int:
		if startIndex == endIndex - 1 or startIndex == endIndex:
			return startIndex
		midIndex = int((startIndex + endIndex) / 2)
		leftIntervalProb = self.getSum(startIndex, midIndex) # includes from start to mid-1
		rightIntervalProb = self.getSum(midIndex, endIndex) # includes from mid to end
		isRightPicked = self.inRight(leftIntervalProb, rightIntervalProb)
		if not isRightPicked:
			return self.pickIndexInInterval(startIndex, midIndex)
		else:
			return self.pickIndexInInterval(midIndex, endIndex)

	def pickIndex(self) -> int:
		return self.pickIndexInInterval(0, len(self.prefixes))


# Your Solution object will be instantiated and called as such:
for i in range(100):
	w = [1, 3]
	obj = Solution(w)
	param_1 = obj.pickIndex()
	print(param_1)
