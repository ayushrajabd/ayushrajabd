class Solution {
public:

    int lowerbound(vector<int>& nums,int n,int x){
        int start=0;int end=n-1;int ans=n;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>=x){
                ans=mid;
                end=mid-1;

            }
            else{
                start=mid+1;
            }

        }
        return ans;
    }
    int upperbound(vector<int>& nums,int n,int x){
        int start=0;int end=n-1;int ans=n;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>x){
                ans=mid;
                end=mid-1;

            }
            else{
                start=mid+1;
            }

        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=lowerbound(nums,n,target);
        if(start==n||nums[start]!=target)return{-1,-1};
        int end=upperbound(nums,n,target);
        return {start,end-1};
    }
};