class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dest = 0
        for index,val in enumerate(nums):
            if dest < index: return False
            if dest == len(nums)-1: break
            dest = max(dest,index+val)
        return True