class Solution {
    struct Event {
        int y;
        int type;
        int x1, x2;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };
    
    vector<int> count;
    vector<double> len;
    vector<int> X;

    void update(int node, int idx_l, int idx_r, int q_l, int q_r, int val) {
        if (q_l >= X[idx_r] || q_r <= X[idx_l]) return;
        
        if (q_l <= X[idx_l] && q_r >= X[idx_r]) {
            count[node] += val;
        } else {
            int mid = idx_l + (idx_r - idx_l) / 2;
            update(2 * node, idx_l, mid, q_l, q_r, val);
            update(2 * node + 1, mid, idx_r, q_l, q_r, val);
        }
        
        if (count[node] > 0) {
            len[node] = (double)X[idx_r] - X[idx_l];
        } else {
            if (idx_r - idx_l == 1) {
                len[node] = 0.0;
            } else {
                len[node] = len[2 * node] + len[2 * node + 1];
            }
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        X.clear();
        for (const auto& sq : squares) {
            X.push_back(sq[0]);
            X.push_back(sq[0] + sq[2]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        
        int m = X.size();
        if (m == 0) return 0.0;

        count.assign(4 * m, 0);
        len.assign(4 * m, 0.0);
        
        vector<Event> events;
        for (const auto& sq : squares) {
            events.push_back({sq[1], 1, sq[0], sq[0] + sq[2]});
            events.push_back({sq[1] + sq[2], -1, sq[0], sq[0] + sq[2]});
        }
        sort(events.begin(), events.end());
        
        vector<pair<int, double>> history; 
        double current_area = 0.0;
        int prev_y = events[0].y;
        
        for (int i = 0; i < events.size(); ) {
            int curr_y = events[i].y;
            double dy = (double)curr_y - prev_y;
            current_area += len[1] * dy;
            
            history.push_back({curr_y, current_area});
            
            while (i < events.size() && events[i].y == curr_y) {
                update(1, 0, m - 1, events[i].x1, events[i].x2, events[i].type);
                i++;
            }
            prev_y = curr_y;
        }
        
        double total_area = current_area;
        double target = total_area / 2.0;
        
        double prev_hist_area = 0.0;
        int prev_hist_y = history[0].first;
        
        for (const auto& h : history) {
            int curr_hist_y = h.first;
            double curr_hist_area = h.second;
            
            if (curr_hist_area >= target) {
                double area_diff = curr_hist_area - prev_hist_area;
                if (area_diff == 0) return (double)prev_hist_y;
                
                double dy = curr_hist_y - prev_hist_y;
                double width = area_diff / dy;
                
                return prev_hist_y + (target - prev_hist_area) / width;
            }
            
            prev_hist_area = curr_hist_area;
            prev_hist_y = curr_hist_y;
        }
        
        return (double)prev_y;
    }
};