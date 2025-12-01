class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;int n=nums.size();
        long long ans=(n*(n+1))/2;
        for(int i:nums){sum+=i;

        }
        int a= (int)ans-sum;
        return a;
    }
};