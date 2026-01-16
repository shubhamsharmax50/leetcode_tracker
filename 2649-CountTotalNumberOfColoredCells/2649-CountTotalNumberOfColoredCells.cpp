// Last updated: 16/1/2026, 8:59:42 pm
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (2L * (long)(n - 1) * n);
    }
};