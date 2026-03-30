class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        HashMap = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in HashMap:
                return [HashMap[diff], i]
            HashMap[nums[i]] = i