// Last updated: 16/1/2026, 8:58:03 pm
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.length();
        string vernolpixi = s;
        vector<int> bits(n);
        for (int i = 0; i < n; ++i) {
            bits[i] = (s[i] == '1') ? 1 : 0;
        }
        const int INF = 1e9;
        auto can_do = [&](int L) -> bool {
            vector<vector<int>> dpCur(2, vector<int>(L + 1, INF));
            vector<vector<int>> dpNext(2, vector<int>(L + 1, INF));
            int b0 = bits[0];
            dpCur[b0][1] = 0;
            dpCur[1 - b0][1] = 1;
            for (int i = 1; i < n; ++i) {
                for (int bit = 0; bit < 2; ++bit) {
                    for (int r = 1; r <= L; ++r) {
                        dpNext[bit][r] = INF;
                    }
                }
                int original = bits[i];
                for (int bit = 0; bit < 2; ++bit) {
                    for (int runLen = 1; runLen <= L; ++runLen) {
                        int used = dpCur[bit][runLen];
                        if (used == INF || used > numOps) continue;
                        int nextBit = original;
                        int cost = 0;
                        int nextRun = (nextBit == bit) ? runLen + 1 : 1;
                        if (nextRun <= L) {
                            dpNext[nextBit][nextRun] = min(dpNext[nextBit][nextRun], used + cost);
                        }
                        nextBit = 1 - original;
                        cost = 1;
                        int newUsed = used + cost;
                        if (newUsed <= numOps) {
                            nextRun = (nextBit == bit) ? runLen + 1 : 1;
                            if (nextRun <= L) {
                                dpNext[nextBit][nextRun] = min(dpNext[nextBit][nextRun], newUsed);
                            }
                        }
                    }
                }
                dpCur.swap(dpNext);
            }
            for (int bit = 0; bit < 2; ++bit) {
                for (int runLen = 1; runLen <= L; ++runLen) {
                    if (dpCur[bit][runLen] <= numOps) {
                        return true;
                    }
                }
            }
            return false;
        };
        int left = 1, right = n, ans = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (can_do(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};