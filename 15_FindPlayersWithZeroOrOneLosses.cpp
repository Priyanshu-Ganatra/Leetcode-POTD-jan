#include <bits/stdc++.h>
using namespace std;

// tc: O(nlogn) & sc: O(m) where n is the number of matches and m is the number of players
vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    map<int, int> mp;

    // loop through matches and update map with wins and losses of each player 
    for (int i = 0; i < matches.size(); i++)
    {
        // if player is not in map, it will be added with value 0. If player is already in map, it will not be added again
        mp[matches[i][0]] += 0; 
        mp[matches[i][1]]++;
    }

    vector<vector<int>> ans(2);
    for (auto a : mp)
    {
        if (a.second == 0)
            ans[0].push_back(a.first);
        if (a.second == 1)
            ans[1].push_back(a.first);
    }

    return ans;
}

int main()
{
    vector<vector<int>> matches = {{2,3}, {1,3}, {5,4}, {6,4}};
    vector<vector<int>> ans = findWinners(matches);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
            cout << "Players with 0 losses: ";
        else
            cout << "Players with 1 loss: ";
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}