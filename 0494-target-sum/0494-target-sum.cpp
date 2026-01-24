class Solution {
public:
    int findways(vector<int> &nums,int tar){
        int n=nums.size();
        vector<int> prev(tar+1,0),curr(tar+1,0);
        if(nums[0]==0)prev[0]=2;
        else prev[0]=1;

        if(nums[0]!=0&&nums[0]<=tar)prev[nums[0]]=1;
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=tar;sum++ ){
                int nottake=prev[sum];
                int take=0;
                if(nums[ind]<=sum)take=prev[sum-nums[ind]];
                curr[sum]=(nottake+take);

            }
            prev=curr;
        }
        return prev[tar];
    }
    int countPartition(int n,int d,vector<int> &nums){
        int totalsum=0;
        for(auto x:nums)totalsum+=x;
        if(totalsum-d<0||(totalsum-d)%2)return false;
        return findways(nums,(totalsum-d)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       int n=nums.size(); 
       return countPartition(n-1,target,nums);
    }
};