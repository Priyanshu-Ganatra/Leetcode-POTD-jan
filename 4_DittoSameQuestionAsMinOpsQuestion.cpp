#include <bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    unordered_map<int, int> mp;
    for (auto &a : tasks)
    {
        mp[a]++;
    }

    int count = 0;
    for (auto &a : mp)
    {
        int &freq = a.second;
        if (freq == 1)
            return -1;
        count += freq / 3; // number of times 3 can divide it
        // freq%3 would either be 1 or 2
        // if it's 1 we can still increase the count as the freq can
        // be made 0 by some combination of operation 1 & 2
        if (freq % 3)
            count++;
    }
    return count;
}

int main()
{
    vector<int> tasks = {1, 1, 1, 2, 2, 2, 3, 3};
    cout << "Minimum number of rounds to make array empty:" << endl;
    cout << minimumRounds(tasks) << endl;
    return 0;
}