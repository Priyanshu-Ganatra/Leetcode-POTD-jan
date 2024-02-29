#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int numJobs = profit.size(); // Number of jobs
    vector<tuple<int, int, int>> jobs(numJobs);

    for (int i = 0; i < numJobs; ++i)
    {
        jobs[i] = {endTime[i], startTime[i], profit[i]};
    }

    sort(jobs.begin(), jobs.end());
    vector<int> dp(numJobs + 1);

    for (int i = 0; i < numJobs; ++i)
    {
        auto [endTime, startTime, profit] = jobs[i];

        int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto &job) -> bool
                                                    { return time < get<0>(job); }) -
                                        jobs.begin();

        dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
    }

    return dp[numJobs];
}

int main()
{
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};

    cout << "Maximum profit:" << endl;
    cout << jobScheduling(startTime, endTime, profit) << endl;

    return 0;
}