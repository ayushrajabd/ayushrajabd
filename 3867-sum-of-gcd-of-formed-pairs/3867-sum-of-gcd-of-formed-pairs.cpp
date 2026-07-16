class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixgcd(n);

        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixgcd[i]=gcd(nums[i],mx);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long ans=0;
        int l=0,r=n-1;
        while(l<r){
            ans+=gcd(prefixgcd[l],prefixgcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};