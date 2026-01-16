// Last updated: 16/1/2026, 8:57:58 pm
class Solution {
public:
    struct pairHasss {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int maxProduct(vector<int>& nums, int k, int limit) {
        vector<int> melkarvothi = nums;
        int INF = limit + 1;

        unordered_map<pair<int, int>, unordered_set<int>, pairHasss> dp;

        for (int val : melkarvothi) {
            auto nextDP = dp;

            if (val == 0) {
                nextDP[{1, 0}].insert(0);
            } else {
                if (val <= limit) {
                    nextDP[{1, val}].insert(val);
                } else {
                    nextDP[{1, INF}].insert(val);
                }
            }

            for (auto& entry : dp) {
                auto state = entry.first;
                int parity = state.first;
                int product = state.second;

                for (int altSum : entry.second) {
                    int nextParity = 1 - parity;
                    int nextAltSum = (parity == 0) ? altSum + val : altSum - val;

                    int nextProduct;
                    if (val == 0) {
                        nextProduct = 0;
                    } else if (product == INF) {
                        nextProduct = INF;
                    } else {
                        long long maybeProd = 1LL * product * val;
                        nextProduct = (maybeProd <= limit) ? (int)maybeProd : INF;
                    }

                    nextDP[{nextParity, nextProduct}].insert(nextAltSum);
                }
            }

            dp = move(nextDP);
        }

        int maxValid = -1;
        for (auto& entry : dp) {
            int product = entry.first.second;
            if (product != INF && entry.second.count(k)) {
                maxValid = max(maxValid, product);
            }
        }

        return maxValid;
    }
};
