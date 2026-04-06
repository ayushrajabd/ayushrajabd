class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> st;
        for (auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (unsigned int)o[1];
            st.insert(key);
        }
        
        int x = 0, y = 0, dir = 0;
        vector<pair<int,int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        int ans = 0;
        
        for (int c : commands) {
            if (c == -1) dir = (dir + 1) % 4;
            else if (c == -2) dir = (dir + 3) % 4;
            else {
                for (int i = 0; i < c; i++) {
                    int nx = x + d[dir].first;
                    int ny = y + d[dir].second;
                    long long key = ((long long)nx << 32) | (unsigned int)ny;
                    if (st.count(key)) break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};