#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        // lower_bound returns an iterator pointing to the first element in the range [first, last) that is not less than
        // (i.e. greater or equal to) given value, or last if no such element is found.
        auto it = lower_bound(res.begin(), res.end(), nums[i]);
        if (it == res.end())
            res.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return res.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS:" << endl;
    cout << lengthOfLIS(nums) << endl;
    return 0;
}