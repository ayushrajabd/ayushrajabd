class Solution {
public:
    bool linearsearch(vector<int> nums,int k){
        bool ans =false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==0)return 0;
        set<int> track;
        for(int i=0;i<n;i++){
            track.insert(nums[i]);
        }int longest=1;int count=0;
        for(auto it:track){
            if(track.find(it-1)==track.end()){
                count=1;
                int x=it+1;
                while(track.find(x)!=track.end()){
                    count++;
                    x++;

                }
                longest=max(longest,count);

            }
        }
        return longest;
    }
};