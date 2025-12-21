class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1;int j=0;
      /* while(i>=0&&j<n){
        if


       }*/
       for(int i=m;i<m+n;i++){
        nums1[i]=nums2[i-m];
       }
       sort(nums1.begin(),nums1.end());
    }
};