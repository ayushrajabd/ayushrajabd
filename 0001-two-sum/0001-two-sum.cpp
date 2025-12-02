class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            int cmp=target-nums[i];
            if(ump.find(cmp)!=ump.end()){
                return{ump[cmp],i};
            }
            ump[nums[i]]=i;
        }
        return {};
        
        
        }
};