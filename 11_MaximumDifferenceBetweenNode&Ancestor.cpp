#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *node, int minValTillNow, int maxValTillNow)
{
    if (!node)
        return maxValTillNow - minValTillNow;
    minValTillNow = min(minValTillNow, node->val);
    maxValTillNow = max(maxValTillNow, node->val);

    int leftDiff = dfs(node->left, minValTillNow, maxValTillNow);
    int rightDiff = dfs(node->right, minValTillNow, maxValTillNow);

    return max(leftDiff, rightDiff);
}

int maxAncestorDiff(TreeNode *root)
{
    if (!root)
        return 0;
    return dfs(root, root->val, root->val);
}

// hardcoded main function for testing
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << "Max difference between node and ancestor:" << endl;
    cout << maxAncestorDiff(root) << endl;
    return 0;
}