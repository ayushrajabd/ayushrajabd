class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size(), m = num2.size();
        vector<int> result(n + m, 0);

        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                result[i + j] += digit1 * digit2;
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }

        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }

        
        reverse(result.begin(), result.end());
        string product;
        for (int digit : result) {
            product += digit + '0';
        }

        return product;
    }
};
