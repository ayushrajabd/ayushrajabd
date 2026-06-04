class Solution {
public:
    int waiveness(int x){
        string w=to_string(x);
        int s=w.size();
        int cnt=0;
        for(int i=1;i<s-1;i++){
            if((w[i]>w[i-1]&&w[i]>w[i+1])||(w[i]<w[i-1]&&w[i]<w[i+1]))cnt++;
        }
        return cnt;

    
    }
    
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=waiveness(i);
        }
        return ans;
    }
};