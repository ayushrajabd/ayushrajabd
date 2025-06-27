class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> mix;double ans=0;int temp=0;
       for(int i=0;i<nums1.size();i++){
        mix.push_back(nums1[i]);
       } 
       for(int i=0;i<nums2.size();i++){
        mix.push_back(nums2[i]);
       }
       sort(mix.begin(),mix.end());

       if(mix.size()%2==1){
         temp=(mix.size()-1)/2;
         ans=mix[temp];

       }
       else{
        temp=(mix.size()/2);
        ans=((double)(mix[temp]+mix[temp-1]))/2;
       }return ans;
    }
};