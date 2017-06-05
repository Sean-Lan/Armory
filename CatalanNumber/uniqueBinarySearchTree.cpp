/**
 *
 * Sean
 * 2017-06-05
 *
 * https://leetcode.com/problems/unique-binary-search-trees/
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        int cnt;
        for (int i=1; i<=n; ++i) {
            cnt = 0;
            for (int j=0; j<i; ++j) {
                cnt += dp[j] * dp[i-1-j];
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
}
