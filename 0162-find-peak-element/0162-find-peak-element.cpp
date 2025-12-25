class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr[0]>arr[1])return i;
            }
            else if(i==n-1){
                if(arr[n-2]<arr[n-1])return i;
            }
            else{
                if(arr[i]>arr[i-1]&&arr[i+1]<arr[i])return i;
            }
        }
        return 0;
    }
};