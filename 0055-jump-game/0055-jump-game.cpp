class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fa=0;
        for(int i=0;i<nums.size();i++){
            if(i>fa)return false;
            fa=max(fa,i+nums[i]);
            if(fa>=nums.size()-1)return true;
        }return true;
        
    }
};