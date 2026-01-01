class Solution {
public:
    int findmaxind(vector<vector<int>> &arr,int n,int m,int col){
        int index=-1;int highest=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i][col]>highest){
                index=i;
                highest=arr[i][col];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxrowind=findmaxind(mat,n,m,mid);
            int left=mid-1>0?mat[maxrowind][mid-1]:-1;
            int right=mid+1<m?mat[maxrowind][mid+1]:-1;
            if(mat[maxrowind][mid]>left&&mat[maxrowind][mid]>right){
                return{maxrowind,mid};
            }
            else if(mat[maxrowind][mid]<left){
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }return{-1,-1};
    }
};