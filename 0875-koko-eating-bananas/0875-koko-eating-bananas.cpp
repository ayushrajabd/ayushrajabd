class Solution {
public:
    int maxelement(vector<int> & arr){
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    int timereq(vector<int> &arr,int k,long long h){
        long long hours = 0;
        for (int x : arr) {
            hours += (x + k - 1) / k; 
             if (hours > h) return hours;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(n==0)return 0;int ans=INT_MAX;
        int low=1;int high=maxelement(piles);
        while(low<=high){
            int mid=(low+high)/2;
            int hourreq=timereq(piles,mid,h);
            if(hourreq<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};