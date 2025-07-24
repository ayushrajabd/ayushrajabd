class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm=p*q/__gcd(p,q);
        int x=lcm/p;
        int y=lcm/q;
        if (x % 2 == 0 && y % 2 == 1) return 0;
        if (x % 2 == 1 && y % 2 == 1) return 1;
        if (x % 2 == 1 && y % 2 == 0) return 2;
    return -1;
    }
};