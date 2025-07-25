class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card : deck) {
            freq[card]++;
        }

        int g = -1;
        for (auto& [card, count] : freq) {
            if (g == -1)
                g = count;
            else
                g = gcd(g, count);
        }

        return g >= 2;
    }
};
