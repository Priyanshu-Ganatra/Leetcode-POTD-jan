#include <bits/stdc++.h>
using namespace std;

// tc : O(n) sc : O(1)
int numberOfArithmeticSlices(vector<int> &nums)
{
    if (nums.size() < 3)
        return 0;

    int curr = 0;
    int total = 0;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            curr++;
            total += curr;
        }
        else
        {
            curr = 0;
        }
    }
    return total;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}