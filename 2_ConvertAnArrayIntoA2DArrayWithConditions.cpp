#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    vector<int> frequency(nums.size() + 1);

    vector<vector<int>> result;
    for (int num : nums)
    {
        if (frequency[num] >= result.size())
        {
            result.push_back({});
        }

        result[frequency[num]].push_back(num);
        frequency[num]++;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    vector<vector<int>> result = findMatrix(nums);

    cout << "Result: " << endl;
    for (vector<int> row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}