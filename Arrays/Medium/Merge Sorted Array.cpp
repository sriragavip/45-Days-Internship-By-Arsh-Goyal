class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = n-- + m-- - 1;
        while(m >= 0){
            if(n == -1 || nums2[m] >= nums1[n]) nums1[i--] = nums2[m--];
            else nums1[i--] = nums1[n--];
        }
    }
};