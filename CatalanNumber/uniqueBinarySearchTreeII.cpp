/**
 *
 * Sean
 * 2017-06-05
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/#/description
 *
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // get all the BSTs in range [start, end]
    vector<TreeNode *> helper(int start, int end) {
        if (start > end) return { nullptr };
        if (start == end) return { new TreeNode(start) };

        vector<TreeNode *> res;

        for (int i=start; i<=end; ++i) {
            auto leftRes = helper(start, i-1);
            auto rightRes = helper(i+1, end);
            for (auto leftChild : leftRes) {
                for (auto rightChild : rightRes) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftChild;
                    root->right = rightChild;
                    res.push_back(root);

                }
            }
        }

        return res;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }
};

int main() {
    return 0;
}
