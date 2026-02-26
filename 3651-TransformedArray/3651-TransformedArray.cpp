// Last updated: 26/2/2026, 9:10:51 pm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int newIndex = (i + nums[i]) % n;

                // Handle negative modulo properly
                if (newIndex < 0)
                    newIndex += n;

                result[i] = nums[newIndex];
            }
        }

        return result;
    }
};
