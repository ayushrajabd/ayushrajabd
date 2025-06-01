class Solution {
public:
    int reverse(int x) {
        
       long long result=0;
       while(x!=0){
        int digit=x%10;
        result=result*10+digit;
        x=x/10;

       }
       if(result<INT_MIN||result>INT_MAX){
        return 0;
       }
       else return static_cast<int>(result);
    }
};