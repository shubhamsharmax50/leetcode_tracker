// Last updated: 16/1/2026, 8:57:54 pm
class Solution {
public:
    bool isPalindrome(const string& str){
        int left = 0 ,right =str.length()-1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
         int lenS = s.length(), lenT = t.length();
        int maxLen = 0;

        
        for (int startS = 0; startS <= lenS; startS++) {
            for (int endS = startS; endS <= lenS; endS++) {
                string subS = s.substr(startS, endS - startS);  

                
                for (int startT = 0; startT <= lenT; startT++) {
                    for (int endT = startT; endT <= lenT; endT++) {
                        string subT = t.substr(startT, endT - startT);  

                        string combined = subS + subT; 
                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.length());
                        }
                    }
                }
            }
        }
        return maxLen;
    }
};