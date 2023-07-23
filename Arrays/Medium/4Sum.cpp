class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        map<vector<int>, int> mp;
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int l = j + 1, r = nums.size() - 1; 
                while(l < r) {
                    long long sum = (long long) nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        mp[{nums[i], nums[j], nums[l], nums[r]}]++;
                        if(mp[{nums[i], nums[j], nums[l], nums[r]}] == 1) ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum < target) l++;
                    else if(sum > target) r--;
                }
            }
        }
        return ans;
    }
};