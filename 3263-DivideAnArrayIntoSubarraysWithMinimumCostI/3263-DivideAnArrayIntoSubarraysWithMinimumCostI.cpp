// Last updated: 26/2/2026, 9:11:12 pm
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int n = nums.size();
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        // Find two smallest elements from index 1 to n-1
        for (int i = 1; i < n; i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        return nums[0] + min1 + min2;
    }
};
