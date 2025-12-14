class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seatIndices;
        
        
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                seatIndices.push_back(i);
            }
        }
        
        
        if (seatIndices.size() == 0 || seatIndices.size() % 2 != 0) {
            return 0;
        }
        
        long long ways = 1;
        int mod = 1e9 + 7;
        
       
        for (int i = 2; i < seatIndices.size(); i += 2) {
            int lengthBetweenPairs = seatIndices[i] - seatIndices[i - 1];
            ways = (ways * lengthBetweenPairs) % mod;
        }
        
        return (int)ways;
    }
};