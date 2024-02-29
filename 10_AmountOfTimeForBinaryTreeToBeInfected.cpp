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

TreeNode *makeParentMappingAndGetTargetNode(unordered_map<TreeNode *, TreeNode *> &nodeToParentMap, TreeNode *root, int &start)
{
    // lvl order traversal
    queue<TreeNode *> nodes;
    TreeNode *target;
    nodes.push(root);
    nodeToParentMap[root] = NULL;

    while (!nodes.empty())
    {
        TreeNode *front = nodes.front();
        nodes.pop();
        if (front->val == start)
        {
            target = front;
        }
        if (front->left)
        {
            nodeToParentMap[front->left] = front;
            nodes.push(front->left);
        }
        if (front->right)
        {
            nodeToParentMap[front->right] = front;
            nodes.push(front->right);
        }
    }
    return target;
}

int startInfection(TreeNode *root, unordered_map<TreeNode *, TreeNode *> nodeToParentMap, TreeNode *target)
{
    unordered_map<TreeNode *, bool> isInfected;
    queue<TreeNode *> currInfectedNodes;
    int T = 0;

    currInfectedNodes.push(target);
    isInfected[target] = true;
    while (!currInfectedNodes.empty())
    {
        bool hasInfectionSpreadOut = 0;
        int size = currInfectedNodes.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *front = currInfectedNodes.front();
            currInfectedNodes.pop();

            if (front->left && !isInfected[front->left])
            {
                currInfectedNodes.push(front->left);
                isInfected[front->left] = true;
                hasInfectionSpreadOut = true;
            }
            if (front->right && !isInfected[front->right])
            {
                currInfectedNodes.push(front->right);
                isInfected[front->right] = true;
                hasInfectionSpreadOut = true;
            }
            if (nodeToParentMap[front] && !isInfected[nodeToParentMap[front]])
            {
                currInfectedNodes.push(nodeToParentMap[front]);
                isInfected[nodeToParentMap[front]] = true;
                hasInfectionSpreadOut = true;
            }
        }
        if (hasInfectionSpreadOut)
            T++;
    }
    return T;
}

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> nodeToParentMap;
    TreeNode *target = makeParentMappingAndGetTargetNode(nodeToParentMap, root, start);
    return startInfection(root, nodeToParentMap, target);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Amount of time for binary tree to be infected:" << endl;
    cout << amountOfTime(root, 5) << endl;
    return 0;
}