#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int solve(int &m, int &n, int maxMove, int row, int col, vector<vector<vector<int>>> &dp)
{
    // base cases
    if (row < 0 || row == m || col < 0 || col == n)
        return 1;
    if (maxMove <= 0)
        return 0;
    if (dp[row][col][maxMove] != -1)
        return dp[row][col][maxMove];

    long long left = solve(m, n, maxMove - 1, row, col - 1, dp);
    long long right = solve(m, n, maxMove - 1, row, col + 1, dp);
    long long up = solve(m, n, maxMove - 1, row - 1, col, dp);
    long long down = solve(m, n, maxMove - 1, row + 1, col, dp);

    int ans = (left + right + up + down) % mod;
    return dp[row][col][maxMove] = ans;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
    return solve(m, n, maxMove, startRow, startColumn, dp);
}

int main()
{
    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    cout << findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}