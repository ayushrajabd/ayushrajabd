class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> besma;
        queue<int> afsma;
        queue<int> bebig;
        queue<int> afbig;
        queue<int> same;
        
        int n=nums.size();
        int pivoti=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                pivoti=i;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]<pivot&&i<pivoti){
                besma.push(nums[i]);
            }
            else if(nums[i]<pivot&&pivoti<i){
                afsma.push(nums[i]);
            }
            else if(nums[i]>pivot&&pivoti>i){
                bebig.push(nums[i]);
            }
            else if(nums[i]>pivot&&pivoti<i){
                afbig.push(nums[i]);
            }
            else{
                same.push(nums[i]);
            }
        }
        vector<int> ans;
        while(!besma.empty()){
            ans.push_back(besma.front());
            besma.pop();
        }
        while(!afsma.empty()){
            ans.push_back(afsma.front());
            afsma.pop();
        }
        while(!same.empty()){
            ans.push_back(same.front());
            same.pop();
        }
        while(!bebig.empty()){
            ans.push_back(bebig.front());
            bebig.pop();
        }
        while(!afbig.empty()){
            ans.push_back(afbig.front());
            afbig.pop();
        }
        return ans;
    }
};