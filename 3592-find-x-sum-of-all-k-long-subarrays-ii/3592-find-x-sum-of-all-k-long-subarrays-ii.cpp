#include <bits/stdc++.h>
using namespace std;

/*
 We maintain:
  - freq: unordered_map<value -> frequency>
  - top: set of pairs (freq, value) ordered by (freq desc, value desc) containing up to x best unique elements
  - rest: same ordering for the remaining unique elements
  - topsum: sum of value*freq over elements currently in 'top'

 Ordering: best element is the one with larger frequency; if tie, larger value.
 We store pairs as (freq, value) and use a comparator that places the best element at begin().
*/

struct PairCmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first > b.first;   // higher freq first
        return a.second > b.second;                         // higher value first
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        if (k > n) return ans;

        unordered_map<int,int> freq; // value -> freq
        set<pair<int,int>, PairCmp> top, rest; // both sorted with best at begin()
        long long topsum = 0;

        auto insert_elem = [&](int val, int f){
            if (f <= 0) return;
            pair<int,int> p = {f, val};
            // put into rest initially
            rest.insert(p);
        };

        // remove a specific pair (old freq) from whichever set contains it
        auto erase_pair = [&](const pair<int,int>& p) -> bool {
            auto it = top.find(p);
            if (it != top.end()) { // in top
                topsum -= 1LL * p.second * p.first;
                top.erase(it);
                return true;
            }
            it = rest.find(p);
            if (it != rest.end()) {
                rest.erase(it);
                return true;
            }
            return false;
        };

        // ensure top contains exactly need elements (or the number of unique elements if less)
        auto rebalance = [&](int need){
            // move best from rest -> top until top.size()==need
            while ((int)top.size() < need && !rest.empty()) {
                auto best = *rest.begin();
                rest.erase(rest.begin());
                top.insert(best);
                topsum += 1LL * best.second * best.first;
            }
            // if top too big, move worst from top -> rest
            while ((int)top.size() > need) {
                // worst in top is the last element according to ordering:
                auto itworst = prev(top.end());
                auto worst = *itworst;
                topsum -= 1LL * worst.second * worst.first;
                top.erase(itworst);
                rest.insert(worst);
            }
            // now maybe some elements in rest are better than some in top -> swap until invariant holds
            while (!rest.empty() && !top.empty()) {
                auto bestRest = *rest.begin();
                auto worstTopIt = prev(top.end());
                auto worstTop = *worstTopIt;
                // if best of rest is strictly better than worst of top, swap them
                if (PairCmp()(bestRest, worstTop)) {
                    // move
                    rest.erase(rest.begin());
                    top.erase(worstTopIt);

                    topsum += 1LL * bestRest.second * bestRest.first;
                    topsum -= 1LL * worstTop.second * worstTop.first;

                    top.insert(bestRest);
                    rest.insert(worstTop);
                } else break;
            }
        };

        // build freq for first window
        for (int i = 0; i < k; ++i) freq[nums[i]]++;
        // insert all unique elements into rest
        for (auto &p : freq) insert_elem(p.first, p.second);
        // promote top x
        int need = min(x, (int)freq.size());
        rebalance(need);
        ans.push_back(topsum);

        // slide
        for (int i = k; i < n; ++i) {
            int add = nums[i];
            int rem = nums[i - k];

            // handle removal: old freq of rem
            int oldf = freq[rem];
            // erase its old pair
            erase_pair({oldf, rem});
            // decrement freq map
            if (--freq[rem] == 0) {
                freq.erase(rem);
            } else {
                // insert updated into rest (we'll rebalance later)
                insert_elem(rem, freq[rem]);
            }

            // handle addition: old freq (0 if not present)
            int oldf_add = 0;
            if (freq.find(add) != freq.end()) oldf_add = freq[add];
            if (oldf_add > 0) {
                // remove old pair
                erase_pair({oldf_add, add});
            }
            // increment
            freq[add] = oldf_add + 1;
            // insert updated into rest
            insert_elem(add, freq[add]);

            // rebalance: need may changed if unique count changed
            need = min(x, (int)freq.size());
            rebalance(need);
            ans.push_back(topsum);
        }

        return ans;
    }
};
