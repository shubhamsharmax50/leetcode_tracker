// Last updated: 26/2/2026, 9:10:32 pm
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> count(26, 0);
            for (int j = i; j < n; ++j) {
                count[s[j] - 'a']++;
                
                if (isValid(count)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }

private:
    bool isValid(const vector<int>& count) {
        int targetFreq = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                if (targetFreq == -1) {
                    targetFreq = count[i];
                } else if (count[i] != targetFreq) {
                    return false;
                }
            }
        }
        return targetFreq != -1;
    }
};