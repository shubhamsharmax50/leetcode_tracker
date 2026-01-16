// Last updated: 16/1/2026, 8:58:00 pm
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (true) {
            int n = nums.size();
            bool sorted = true;

            for (int i = 0; i < n - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }

           
            if (sorted) break;

           
            int minSum = INT_MAX;
            int minIdx = 0;

            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }

            vector<int> newNums;
            for (int i = 0; i < n; i++) {
                if (i == minIdx) {
                    newNums.push_back(nums[i] + nums[i + 1]);
                    i++; 
                } else {
                    newNums.push_back(nums[i]);
                }
            }

            nums = newNums;
            count++;
        }

        return count;
    }
};
