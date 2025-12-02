class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> ans(nums.size());
       vector<int> pos;
       vector<int> neg;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            pos.push_back(nums[i]);
        }
        else{
            neg.push_back(nums[i]);
        }}
        if(pos.size()>neg.size()){
            for(int i=0;i<neg.size();i++){
                ans[2*i]=pos[i];
                ans[2*i+1]=neg[i];
            }
            int index=2*neg.size();
            for(int i=neg.size();i<pos.size();i++){
                ans[index]=pos[i];index++;
            }
        }
        else{
            for(int i=0;i<pos.size();i++){
                ans[2*i]=pos[i];
                ans[2*i+1]=neg[i];
            }
            int index=2*pos.size();
            for(int i=pos.size();i<neg.size();i++){
                ans[index]=neg[i];index++;
            }
        

       }return ans;
    }
};