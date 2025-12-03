class Solution {
public:
    bool linearsearch(vector<int> nums,int k){
        bool ans =false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int longest=1;int curr=1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){
                curr++;
                longest=max(longest,curr);
            }
            else if(nums[i+1]!=nums[i]+1&&nums[i+1]!=nums[i]){
                curr=1;
            }

        }return longest;
    }
};