class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0; int sum=0;
        int minlen=INT_MAX;

        for(int right=0;right<n;right++){
            sum+=nums[right];
            
        
        while(sum>=target){
            minlen=std::min(minlen,right-left+1);
            sum-=nums[left++];
        }}
        return minlen==INT_MAX?0:minlen;
    }
};