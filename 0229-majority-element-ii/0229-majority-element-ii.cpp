class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
       int cnt1=0;int cnt2=0;
       int el1=INT_MIN;
       int el2=INT_MIN;
       for(int i=0;i<n;i++){
        if(cnt1==0&&nums[i]!=el2){
            cnt1=1;
            el1=nums[i];
        }
        else if(cnt2==0&&nums[i]!=el1){
            cnt2=1;
            el2=nums[i];
        }
        else if(nums[i]==el1)cnt1++;
         else if(nums[i]==el2)cnt2++;
         else{
            cnt1--;cnt2--;
         }
       } 
       int count1=0,count2=0;
       vector<int> res;
       for(int i=0;i<n;i++){
        if(nums[i]==el1)count1++;
        else if(nums[i]==el2)count2++;
       }
       if(count1>=n/3+1){
        res.push_back(el1);
       }
       if(count2>=n/3+1){
        res.push_back(el2);
       }
       return res;
    }
};