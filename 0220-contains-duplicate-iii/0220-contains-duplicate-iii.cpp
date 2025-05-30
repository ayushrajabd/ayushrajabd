class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
      int s=nums.size();int k=indexDiff;
      set<long long>window;
      for(int i=0;i<s;i++){
        auto it=window.lower_bound((long long)nums[i]-valueDiff);
        if(it!=window.end()&& *it<=(long long)nums[i]+valueDiff)return true;

        window.insert(nums[i]);
        if(window.size()>k)
        window.erase(nums[i-k]);
      }return false;
    }
};