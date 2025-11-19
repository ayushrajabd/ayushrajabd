class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int temp=original;
        for(int i=0;i<n;i++){
            if(nums[i]==temp){
                temp=2*temp;
            }
            else if(nums[i]>temp){
                return temp;
            }
        }
        return temp;
    }
};