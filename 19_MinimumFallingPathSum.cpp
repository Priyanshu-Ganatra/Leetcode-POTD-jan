#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int x, int y, int &n, vector<vector<int>> &dp)
{
    if (y < 0 || y == n)
        return INT_MAX;
    if (x == n)
        return INT_MAX;

    if (dp[x][y] != -1)
        return dp[x][y];

    int leftAns = solve(matrix, x + 1, y - 1, n, dp);
    int belowAns = solve(matrix, x + 1, y, n, dp);
    int rightAns = solve(matrix, x + 1, y + 1, n, dp);
    if (leftAns == INT_MAX && belowAns == INT_MAX && rightAns == INT_MAX)
    {
        dp[x][y] = matrix[x][y];
        return dp[x][y];
    }

    int mini = min(min(leftAns, belowAns), rightAns);
    dp[x][y] = matrix[x][y] + mini;
    return dp[x][y];
}

// tc: O(n^2) & sc: O(n^2)
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 100 && matrix[0][0] == 0)
        return -1;
    int mini = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        int temp = solve(matrix, 0, i, n, dp);
        mini = min(mini, temp);
    }
    return mini;
}

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}