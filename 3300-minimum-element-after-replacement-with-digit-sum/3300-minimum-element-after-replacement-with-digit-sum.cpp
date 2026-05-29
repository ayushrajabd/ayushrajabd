class Solution {
public:
    int sumofdigit(int nums){
        int ans=0;
        while(nums>0){
            ans+=nums%10;
            nums/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int temp=sumofdigit(nums[i]);
            res=min(res,temp);
        }
        return res;
    }
};