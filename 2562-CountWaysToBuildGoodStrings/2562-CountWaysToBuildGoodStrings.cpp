// Last updated: 26/2/2026, 9:12:06 pm
class Solution {
public:
    const int M = 1e9+7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> t(high+1, 0);
        //t[i] = Total number of good strings of length i
        
        t[0] = 1; //Only one good string ""
        
        for(int i = 1; i <= high; i++) {
            
            if(i - zero >= 0)
                t[i] = (t[i]%M + t[i-zero]%M)%M;
            
            if(i - one >= 0)
                t[i] = (t[i]%M + t[i-one]%M)%M;
            
        }
        
        int ans = 0;
        
        for(int l = low; l <= high; l++) {
            ans = (ans%M + t[l]%M)%M;
        }
        
        return ans;
    }
};