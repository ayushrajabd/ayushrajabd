class Solution {
public:

    
    
    vector<int> searchRange(vector<int>& nums, int x) {
        int n=nums.size();
        int low=0;int high=n-1;int fo=-1;int lo=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==x){
                fo=mid;
                high=mid-1;
            }
            else if(nums[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
         low=0; high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==x){
                lo=mid;
                low=mid+1;
            }
            else if(nums[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return{fo,lo};
    }
};