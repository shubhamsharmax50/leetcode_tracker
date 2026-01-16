// Last updated: 16/1/2026, 8:58:05 pm
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
                int result = 0;

                        for(int i = 1; i < n-1; i++) {
                                    if(nums[i] == (nums[i-1] + nums[i+1])*2) {
                                                    result++;
                                                                }
                                                                        }

                                                                                return result;
    }
};