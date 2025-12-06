class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;mp[0]=1;
        int prefix=0;int count=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int rem=prefix-k;
            if(mp.find(rem)!=mp.end()){
            count+=mp[rem];}
            mp[prefix]++;

        }
        return count;
    }
};