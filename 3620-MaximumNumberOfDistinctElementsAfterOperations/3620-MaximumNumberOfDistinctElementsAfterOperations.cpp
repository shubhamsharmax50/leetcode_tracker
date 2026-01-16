// Last updated: 16/1/2026, 8:58:19 pm
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array to process in order
        
        int distinct_count = 0;
        int last_used = INT_MIN;

        for (int num : nums) {
            int start = max(num - k, last_used + 1);
            if (start <= num + k) {
                last_used = start; // Use the current position
                distinct_count++;
            }
        }

        return distinct_count;
    }
};
