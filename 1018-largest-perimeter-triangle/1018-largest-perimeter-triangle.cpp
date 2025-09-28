class Solution {
public:
    bool trianglevalid(int a,int b,int c){
        bool ans=true;
        if(a+b<=c)return false;
        if(b+c<=a)return false;
        if(c+a<=b)return false;
        return true;

    }
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n<2)return ans;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            if(trianglevalid(nums[i],nums[i-1],nums[i-2])){
                ans=max(ans,nums[i]+nums[i-1]+nums[i-2]);
            }
        }
        return ans;
    }
};