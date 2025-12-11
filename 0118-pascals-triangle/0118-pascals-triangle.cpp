class Solution {
public:
    vector<int> generaterow(int n){
        vector<int> ans;
        ans.push_back(1);
        int a=1;
        for(int i=1;i<n;i++){
            a*=(n-i);
            a/=i;
            ans.push_back(a);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> give;
        for(int i=1;i<=numRows;i++){
            give.push_back(generaterow(i));
        }
        return give;
    }
};