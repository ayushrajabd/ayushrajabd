class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=apple[i];

        }
        int check=0;int ans=0;
        for(int i=0;i<m;i++){
            check+=capacity[i];
            if(check>=sum){
                ans=i+1;break;
            }
        }
        return ans;


    }
};