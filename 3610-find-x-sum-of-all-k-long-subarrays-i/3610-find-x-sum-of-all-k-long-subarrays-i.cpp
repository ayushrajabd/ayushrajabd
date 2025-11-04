class Solution {
public:
    int sum(vector<int>& nums,int x){
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        vector<pair<int,int>> v(ump.begin(),ump.end());
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            if(a.second==b.second)return a.first>b.first;
            return a.second>b.second;
            });

        int total=0;int cnt=0;
        for(auto &p:v){
            if(cnt==x)break;
            total+=p.first*p.second;
            cnt++;
        }  return total;  

 }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<=n-k;i++){
            vector<int> sub(nums.begin()+i,nums.begin()+i+k);
            ans.push_back(sum(sub,x));
        }
        return ans;
        
    }
};