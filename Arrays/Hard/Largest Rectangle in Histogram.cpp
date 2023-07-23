class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        vector<int> left_small(n);
        left_small[0] = 0;
        stack<int> s;
        s.push(0);

        for(int i = 1; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) left_small[i] = 0;
            else left_small[i] = s.top()+1;
            s.push(i);
        }
        
        stack<int> s2;
        vector<int> right_small(n);
        right_small[n-1] = n-1;
        s2.push(n-1);

        for(int i = n-2; i >= 0; i--) {
            while(!s2.empty() && heights[s2.top()] >= heights[i]) s2.pop();
            if(s2.empty()) right_small[i] = n-1;
            else right_small[i] = s2.top() - 1;
            s2.push(i);
        }

        for(int i = 0; i < n; i++) {
            int area = heights[i] * (right_small[i]-left_small[i]+1);
            res = max(res, area);
        }
        return res;
    }
};