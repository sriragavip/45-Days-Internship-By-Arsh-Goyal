class Solution 
{
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size(), c = 0;
        
        unordered_map<int,vector<int>> rows, cols;
        for (int s = 0; s < n; ++s)
            rows[stones[s][0]].push_back(s),
            cols[stones[s][1]].push_back(s);
        
        unordered_set<int> seen;

        function<int(int)> dfs;
        dfs = [&](int s) -> int
        {
            if (seen.count(s)) return 0;
            seen.insert(s);
            int r = stones[s][0], c = stones[s][1];
            for (auto ss : rows[r]) dfs(ss);
            for (auto ss : cols[c]) dfs(ss);
            return 1;
        };
        
        for (int s = 0; s < n; ++s)
            c += dfs(s);
        
        return n-c;
    }
};