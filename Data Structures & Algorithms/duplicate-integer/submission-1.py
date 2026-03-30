class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hasher= {}
        for i in nums:
            if i in hasher:
                return True
            hasher[i]= 1

        return False
         