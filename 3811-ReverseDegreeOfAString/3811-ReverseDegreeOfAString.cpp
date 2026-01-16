// Last updated: 16/1/2026, 8:57:51 pm
class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0 ;
        for( int i =0 ; i< s.length() ;i++){
            int initialPosition = i+1 ;
            int reverse = 26-(s[i]-'a');

            totalSum += reverse * initialPosition ;
        }
        return totalSum ;
    }
};