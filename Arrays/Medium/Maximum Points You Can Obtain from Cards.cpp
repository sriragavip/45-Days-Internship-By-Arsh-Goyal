class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, sum=0;
        
        vector<int>preSum(cardPoints.size()+1,0);
        for(int i=0;i<cardPoints.size();i++) {
            preSum[i+1]=preSum[i]+cardPoints[i];
        }
        
        ans = preSum[k];
        reverse(cardPoints.begin(),cardPoints.end()); 
        for(int i=0;i<k;i++) {
            sum+=cardPoints[i];
            ans = max(ans, sum + preSum[k-1-i]);
        }  
         
      return ans;  
    }
};