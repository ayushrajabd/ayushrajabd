class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (i < n1 || j < n2) {
            
            string part1;
            while (i < n1 && version1[i] != '.') {
                part1.push_back(version1[i]);
                i++;
            }
           
            string part2;
            while (j < n2 && version2[j] != '.') {
                part2.push_back(version2[j]);
                j++;
            }

            
            if (i < n1 && version1[i] == '.') i++;
            if (j < n2 && version2[j] == '.') j++;

            
            int k1 = 0; 
            while (k1 < (int)part1.size() && part1[k1] == '0') k1++;
            part1 = (k1 == (int)part1.size()) ? "0" : part1.substr(k1);

            int k2 = 0;
            while (k2 < (int)part2.size() && part2[k2] == '0') k2++;
            part2 = (k2 == (int)part2.size()) ? "0" : part2.substr(k2);

           
            if (part1.size() < part2.size()) return -1;
            if (part1.size() > part2.size()) return 1;

            
            if (part1 < part2) return -1;
            if (part1 > part2) return 1;
        }

        return 0;
    }
};
