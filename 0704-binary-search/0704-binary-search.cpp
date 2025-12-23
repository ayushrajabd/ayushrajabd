class Solution {
public:
    int binarysearch(vector<int>& arr,int low,int high,int target){
        if(low>high){return -1;}
       int mid=(low+high)/2;
       if(arr[mid]==target)return mid;
       else if(arr[mid]>target){
        return binarysearch(arr,low,mid-1,target);

       }
       else{return binarysearch(arr,low+1,high,target);}
    }
    int search(vector<int>& arr, int target) {
       int n=arr.size();
       int low=0;int high=n-1;
       int t=target;
       int a=binarysearch(arr,low,high,t);
       return a;
    }
};