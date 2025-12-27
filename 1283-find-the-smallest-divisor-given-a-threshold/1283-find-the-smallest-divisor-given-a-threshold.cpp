class Solution {
public:
    long long sumofel(vector<int>& nums){
        int n=nums.size();long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

        }
        return sum;
    }
    bool func(vector<int>& arr,int no,int threshold){
        int n=arr.size();long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(arr[i]-1+no)/no;

        }
        if(ans<=threshold){return true;}
        return false;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n==0)return 0;
        int low=1;int high=*max_element(nums.begin(),nums.end());int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            bool check=func(nums,mid,threshold);
            if(check==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};