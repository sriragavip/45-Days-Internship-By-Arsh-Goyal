class Solution {
public:  
     int ok(vector<int>& nums,int mid){ 
         int  count=0;
            for(auto value:nums){
               if(value<=mid){
                   count++;
             }
            }
            return count ;
      }
   int findDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(low<high){
            mid=low+(high-low)/2;
    
            if(ok(nums,mid)>mid){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};