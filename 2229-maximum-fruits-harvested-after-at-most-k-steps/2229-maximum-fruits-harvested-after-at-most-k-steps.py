from typing import List

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        # Extract positions and amounts
        positions = [pos for pos, _ in fruits]
        amounts = [amt for _, amt in fruits]

        # Prefix sum to calculate fruit amount in range efficiently
        prefix = [0] * (len(fruits) + 1)
        for i in range(len(fruits)):
            prefix[i + 1] = prefix[i] + fruits[i][1]

        def get_total(l: int, r: int) -> int:
            """Return total fruits in the range [l, r] (inclusive)"""
            return prefix[r + 1] - prefix[l]

        n = len(fruits)
        max_fruit = 0
        left = 0

        # Try all right boundaries with two strategies
        for right in range(n):
            # Check if the subrange [left, right] is reachable within k steps
            while left <= right and min(
                abs(startPos - positions[left]) + (positions[right] - positions[left]),
                abs(startPos - positions[right]) + (positions[right] - positions[left])
            ) > k:
                left += 1
            if left <= right:
                max_fruit = max(max_fruit, get_total(left, right))

        return max_fruit
