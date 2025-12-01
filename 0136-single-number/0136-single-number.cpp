class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int i:nums){
            ump[i]++;
        }
        for(auto x:ump){
            if(x.second==1){
                return x.first;
            }
        }return 0;
    }
};