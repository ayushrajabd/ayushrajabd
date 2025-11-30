class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        long long sum=0;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long cost=1LL*nums[i]*(i-l+1)-sum;
            while(cost>k){
                sum-=nums[l];
                l++;
                cost=1LL*nums[i]*(i-l+1)-sum;
            }
            ans=max(ans,i-l+1);
        }return ans;
    }
};