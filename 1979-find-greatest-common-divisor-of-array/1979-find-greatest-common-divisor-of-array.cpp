class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int start=nums[0];
        int end=nums[nums.size()-1];
        int k=max(start,end);
        int ans=1;

        for(int i=k;k>=1;k--){
            if((start%k==0)&&(end%k==0)){
                ans=k;
                break;
            }
        }
        return ans;
    }
};