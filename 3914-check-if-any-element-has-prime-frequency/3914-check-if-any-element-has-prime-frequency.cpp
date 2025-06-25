class Solution {
public:
    bool isprime(int n){
        if(n<=1)return false;
        if(n<=3)return true;
        if(n%2==0||n%3==0)return false;
        for(int i=5;i*i<=n;i=i+6){
            if(n%i==0||n%(i+2)==0){
                return false;
            }
        }return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>check;
        for(int i=0;i<nums.size();i++){
            check[nums[i]]++;
        }
        for(const auto&pair:check){
            if(isprime(pair.second))return true;
        }
        return false;
    }
};