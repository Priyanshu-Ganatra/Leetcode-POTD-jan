#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solver(TreeNode *root, int low, int high, int &sum)
{
    if (!root)
        return;

    if (root->val >= low && root->val <= high)
        sum += root->val;
    solver(root->left, low, high, sum);
    solver(root->right, low, high, sum);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int sum = 0;
    solver(root, low, high, sum);
    return sum;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(18);

    cout << "Range Sum of BST:" << endl;
    cout << rangeSumBST(root, 7, 15) << endl;
    return 0;
}