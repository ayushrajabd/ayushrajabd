class Solution {
public://dutch flag Algorithm
    void sortColors(vector<int>& nums) {int count0=0,count1=0,count2=0;
        int low=0;int mid=0;int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;mid++;

            }
            else if(nums[mid]==1){mid++;

            }
            else {
                swap(nums[mid],nums[high]);
                high--;

            }
        }
    }
};