// Last updated: 16/1/2026, 8:58:02 pm
class Solution {
public:
    string findValidPair(string s) {
        int n = s.length();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[s[i] - '0']++;
        }

        for (int i = 0; i < n - 1; i++) {  
               if (s[i] != s[i+1] && mp[s[i] - '0'] == (s[i] - '0') && mp[s[i+1] - '0'] == (s[i+1] - '0')) {
         return string(1, s[i]) + string(1, s[i+1]);  
            }
        }

        return "";  
    }
};
