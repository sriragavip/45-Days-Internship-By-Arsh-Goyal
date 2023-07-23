class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
       int ans=INT_MIN , n= points.size();
        //Values are already sorted by x -coordinates

        // Using equation : Yi + Yj +|Xi-Xj| = Yi-Xi + (Yj + Xj)
        // In Priority queue we are storing two values :
        //     first= Yi- Xi
        //     second =Xi
       priority_queue<pair<int, int>>pq;
       for(int i=0;i<n;i++){
        //    int first=pq.top().first;
        //    int second=pq.top().second;

           while((!pq.empty() )and (points[i][0]-pq.top().second)>k)pq.pop();
           if(!pq.empty()){
               ans=max(ans, (points[i][0]+points[i][1] + pq.top().first));
           }
           pq.push({points[i][1]-points[i][0], points[i][0]});
       } 
       return ans;
    }
};