class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        val={}
        for i in nums:
            if i in val:
                val[i]+=1
            else:
                val[i]=1
        keys=[key for key,values in val.items() if values==2]
        return keys