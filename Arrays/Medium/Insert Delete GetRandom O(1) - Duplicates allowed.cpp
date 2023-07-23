class RandomizedCollection {
    unordered_map<int, vector<int>> mark;
    vector<pair<int, int>> v;
    mt19937 rand;
public:
    RandomizedCollection() {
        random_device seed;
        rand = mt19937(seed());
    }
    
    bool insert(int val) {
        bool ret{false};
        if (mark.find(val) == mark.end()) {
            ret = true;
            mark[val] = vector<int>();
        }
        mark[val].push_back(v.size());
        v.emplace_back(val, mark[val].size()-1);
        return ret;
    }
    
    bool remove(int val) {
        auto it = mark.find(val);
        if (it == mark.end()) return false;
        int del_idx = it->second.back();
        v[del_idx] = v.back();
        auto [mov_val, mov_idx] = v.back();
        mark[mov_val][mov_idx] = del_idx;
        
        v.pop_back();
        it->second.pop_back();
        if (it->second.empty())
            mark.erase(it);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()].first;
    }
};