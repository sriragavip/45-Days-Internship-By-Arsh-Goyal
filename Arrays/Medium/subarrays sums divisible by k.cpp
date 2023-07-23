class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            int remaining =sum%k;
            if(remaining<0)
                remaining+=k;
            count=count+mp[remaining];
            mp[remaining]++;
        }
        return count;
    }
};