class Solution {
public:
    int finddays(vector<int>&nums,int mid){
        int days=1;int load=0;int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]+load>mid){
                days+=1;
                load=nums[i];
            }
            else{
                load+=nums[i];
            }

        }return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int noofdays=finddays(weights,mid);
            if(noofdays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};

