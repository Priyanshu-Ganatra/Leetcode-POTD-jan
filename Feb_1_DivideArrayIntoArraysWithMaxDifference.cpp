#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i += 3)
    {
        if (nums[i + 2] - nums[i] > k)
        {
            return {};
        }
        ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 0;
    vector<vector<int>> ans = divideArray(nums, k);
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}