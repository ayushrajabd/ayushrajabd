class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int s=nums.size();
        int n=s/2;
        unordered_map<int,int> ump;
        for(auto x:nums){
            ump[x]++;
        }
        for(auto it:ump){
            if(it.second==n)return it.first;
        }
        return 0;

    }
};