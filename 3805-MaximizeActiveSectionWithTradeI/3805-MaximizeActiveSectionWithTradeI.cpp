// Last updated: 16/1/2026, 8:57:53 pm
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int length = s.size(), activeCount = 0;

        for (char ch : s) {
            if (ch == '1') activeCount++;
        }

        string modifiedStr = "1" + s + "1";
        int newLength = modifiedStr.size(), maxSectionss = activeCount;

        for (int i = 1; i < newLength - 1;) {
            if (modifiedStr[i] == '1') {
                int j = i;

                while (j < newLength && modifiedStr[j] == '1') j++;

                if (j < newLength - 1 && modifiedStr[i - 1] == '0' && modifiedStr[j] == '0') {
                    int leftZeros = 0, rightZeros = 0, left = i - 1, right = j;

                    while (left >= 0 && modifiedStr[left] == '0') {
                        leftZeros++;
                        left--;
                    }

                    while (right < newLength && modifiedStr[right] == '0') {
                        rightZeros++;
                        right++;
                    }

                    maxSectionss = max(maxSectionss, activeCount + leftZeros + rightZeros);
                }

               if(i = j) ;
            } else {
                i++; 
            }
        }

        return maxSectionss;
    }
};
