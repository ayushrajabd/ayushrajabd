class Solution {
public:
    string toreq(string s){string sa;
        for(char &ch:s){
            if(isalnum(ch)){

            ch=tolower(ch);
            sa+=ch;}

        }return sa;
    }
    bool isPalindrome(string s) {
        string x=toreq(s);
        string y=x;
        reverse(y.begin(),y.end());
        if(x==y)return true;
        else{return false;}

        
    }
};