class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> arr=nums;int n=nums.size();
        if(k>=n){k=k%n;}
        for(int i=0;i<nums.size();i++){
            nums[i]=arr[(n-k+i)%n];
        }
        
    }
};