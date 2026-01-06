class Solution {
public:
    int cal(vector<int>& nums){
        int n=nums.size();
       vector<int> dp(n,-1);
       if(n==0)return 0;if(n==1)return nums[0];
       dp[0]=nums[0];
       for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=dp[i-2];
        int nottake=dp[i-1];
        dp[i]=max(take,nottake);}
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==0)return 0;
       if(n==1)return nums[0];
       vector<int> first(nums.begin(),nums.end()-1);
       vector<int> last(nums.begin()+1,nums.end());
       int a=cal(first);
       int b=cal(last);
       return max(a,b);


       

    }
};