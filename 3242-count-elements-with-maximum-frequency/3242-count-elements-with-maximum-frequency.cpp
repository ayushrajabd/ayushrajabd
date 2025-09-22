class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int a:nums){
            ump[a]++;
        }
        int mx=0;
        for(auto p:ump){
            mx=max(mx,p.second);
        }
        int ans=0;
        for(auto p:ump){
            if(p.second==mx){
                ans+=p.second;
            }
        }
        return ans;
    }
};