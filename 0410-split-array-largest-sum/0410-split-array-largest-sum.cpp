class Solution {
public:
    int noofpart(vector<int>& nums,int maxi){
        int n=nums.size();
        int count=1;int prev=0;
        for(int i=0;i<n;i++){
            if(nums[i]+prev>maxi){
                count++;
                prev=nums[i];
            }
            else{
                prev+=nums[i];
            }
        }return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);int ans=-1;
        while(low<=high){
            int mid=(low)+(high-low)/2;
            int nopart=noofpart(nums,mid);
            if(nopart<=k){
                ans=mid; high=mid-1;
                
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
};