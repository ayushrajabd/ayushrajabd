class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minRow(n + 1, n + 1);
        vector<int> maxRow(n + 1, 0);
        vector<int> minCol(n + 1, n + 1);
        vector<int> maxCol(n + 1, 0);

        for (auto& b : buildings) {
            int r = b[0];
            int c = b[1];
            if (r < minRow[c]) minRow[c] = r;
            if (r > maxRow[c]) maxRow[c] = r;
            if (c < minCol[r]) minCol[r] = c;
            if (c > maxCol[r]) maxCol[r] = c;
        }

        int count = 0;
        for (auto& b : buildings) {
            int r = b[0];
            int c = b[1];
            if (r > minRow[c] && r < maxRow[c] && c > minCol[r] && c < maxCol[r]) {
                count++;
            }
        }
        return count;
    }
};