// Last updated: 26/2/2026, 9:12:14 pm
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
                
                        int minPosition = -1;
                                int maxPosition = -1;
                                        int leftBound   = -1;
                                                
                                                        for(int i = 0; i < nums.size(); i++) {
                                                                    
                                                                                if(nums[i] < minK || nums[i] > maxK)
                                                                                                leftBound = i;
                                                                                                            
                                                                                                                        if(nums[i] == minK)
                                                                                                                                        minPosition = i;
                                                                                                                                                    if(nums[i] == maxK)
                                                                                                                                                                    maxPosition = i;
                                                                                                                                                                                
                                                                                                                                                                                            int count = min(maxPosition, minPosition) - leftBound;
                                                                                                                                                                                                        
                                                                                                                                                                                                                    ans += (count <= 0) ? 0 : count;
                                                                                                                                                                                                                                
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                        return ans;
    }
};