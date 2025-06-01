class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}

        int org=x;long long rev=0;int digit;
        while(org>0){
            digit=org%10;
            rev=rev*10+digit;
            org=org/10;
        }
        return (static_cast<int>(rev))==x;
        
    }
};