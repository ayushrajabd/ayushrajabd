class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
    
    int l=nums.size();
    int start=nums[0];
    int end=nums[l-1];
    int k=max(start,end);
    for(int i=k;i>0;i--){
        if((start%i==0)&&(end%i==0)){
            return i;
        }
    }return 1;
    }
};