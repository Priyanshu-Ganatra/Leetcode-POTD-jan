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

void solve(TreeNode *root, vector<int> &leaves)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        leaves.push_back(root->val);
    solve(root->left, leaves);
    solve(root->right, leaves);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> leaves1;
    vector<int> leaves2;
    solve(root1, leaves1);
    solve(root2, leaves2);
    if (leaves1 == leaves2)
        return true;
    else
        return false;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);

    if (leafSimilar(root1, root2))
        cout << "Yes, the two trees are leaf similar";
    else
        cout << "No, the two trees are not leaf similar";
    return 0;
}