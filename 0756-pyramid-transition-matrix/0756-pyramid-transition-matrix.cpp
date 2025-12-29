class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool solve(string bottom) {
        
        if (bottom.size() == 1) return true;

        
        if (memo.count(bottom)) return memo[bottom];

        string next = "";
        bool canBuild = buildNext(bottom, 0, next);

        memo[bottom] = canBuild;
        return canBuild;
    }

    bool buildNext(string &bottom, int idx, string &next) {
        if (idx == bottom.size() - 1) {
            return solve(next);
        }

        string key = bottom.substr(idx, 2);
        if (mp.find(key) == mp.end()) return false;

        for (char ch : mp[key]) {
            next.push_back(ch);
            if (buildNext(bottom, idx + 1, next)) return true;
            next.pop_back();
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return solve(bottom);
    }
};
