class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        int partitionsum=0;int diff=0;int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            partitionsum+=nums[i];
            int diff=2*(partitionsum)-totalsum;
            if(diff%2==0){
                ans++;
            }
        }
        return ans;
        
    }
};