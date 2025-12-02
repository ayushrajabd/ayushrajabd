class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();int ans=0;int maxp=-1;int minp=INT_MAX;
        for(int i=0;i<n;i++){
            
             minp=min(arr[i],minp);
             maxp=max(arr[i]-minp,maxp);
        }
        ans= maxp-minp;
        return maxp;
    }
};